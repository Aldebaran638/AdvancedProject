package com.zeroone.star.communitymanage.config;

import com.zeroone.star.communitymanage.exception.ResourceNotFoundException;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import org.springframework.dao.DuplicateKeyException;
import org.springframework.validation.BindException;
import org.springframework.validation.BindingResult;
import org.springframework.validation.FieldError;
import org.springframework.web.HttpMediaTypeException;
import org.springframework.web.bind.MethodArgumentNotValidException;
import org.springframework.web.bind.MissingServletRequestParameterException;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RestControllerAdvice;

import javax.validation.ConstraintViolation;
import javax.validation.ConstraintViolationException;
import javax.validation.Path;
import java.sql.SQLIntegrityConstraintViolationException;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

/**
 * <p>
 * 描述：全局异常捕获处理
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@RestControllerAdvice
public class GlobalExceptionHandler {
    /**
     * 系统通用异常处理
     * @param e 异常类型
     * @return 返回异常信息回显数据
     */
    @ExceptionHandler(value = Exception.class)
    public JsonVO<String> exceptionHandler(Exception e) {
        if (e instanceof org.springframework.jdbc.UncategorizedSQLException) {
            Throwable cause = e.getCause();
            if (cause instanceof SQLIntegrityConstraintViolationException) {
                return handleSQLIntegrity((SQLIntegrityConstraintViolationException) cause);
            }
        }
        if (e instanceof org.mybatis.spring.MyBatisSystemException) {
            Throwable cause = e.getCause();
            if (cause instanceof SQLIntegrityConstraintViolationException) {
                return handleSQLIntegrity((SQLIntegrityConstraintViolationException) cause);
            }
        }
        if (e instanceof HttpMediaTypeException) {
            return JsonVO.create(e.getMessage(), ResultStatus.CONTENT_TYPE_ERR);
        }
        return JsonVO.create(e.getMessage(), ResultStatus.SERVER_ERROR);
    }

    /**
     * requestBody参数校验异常处理
     * @param e 异常类型
     * @return 返回异常信息回显数据
     */
    @ExceptionHandler(value =
            {MethodArgumentNotValidException.class, BindException.class})
    public JsonVO<String> methodArgumentNotValidHandler(Exception e) {
        BindingResult bindingResult;
        if (e instanceof MethodArgumentNotValidException) {
            //@RequestBody参数校验
            bindingResult = ((MethodArgumentNotValidException) e).getBindingResult();
        } else {
            //@ModelAttribute参数校验
            bindingResult = ((BindException) e).getBindingResult();
        }
        FieldError fieldError = bindingResult.getFieldError();
        String data = "";
        if (fieldError != null) {
            data = "[" + fieldError.getField() + "]" + fieldError.getDefaultMessage();
        }
        return JsonVO.create(data, ResultStatus.PARAMS_INVALID);
    }

    /**
     * requestParam参数校验异常处理
     * @param e 异常类型
     * @return 返回异常信息回显数据
     */
    @ExceptionHandler(value = {
            ConstraintViolationException.class,
            MissingServletRequestParameterException.class})
    public JsonVO<String> constraintViolationHandler(Exception e) {
        String field = "";
        String msg = "";
        if (e instanceof ConstraintViolationException) {
            ConstraintViolation<?> constraint = ((ConstraintViolationException) e)
                    .getConstraintViolations().stream().findFirst().orElse(null);
            if (constraint != null) {
                List<Path.Node> pathList = StreamSupport.stream
                                (constraint.getPropertyPath().spliterator(), false)
                        .collect(Collectors.toList());
                field = pathList.get(pathList.size() - 1).getName();
                msg = constraint.getMessage();
            }
        } else {
            // 非JSR标准返回的异常，要自定义提示文本
            field = ((MissingServletRequestParameterException) e).getParameterName();
            msg = "参数值缺失";
        }
        return JsonVO.create("[" + field + "]" + msg, ResultStatus.PARAMS_INVALID);
    }

    // 新增MyBatis包装异常处理
    @ExceptionHandler(value = {
            DuplicateKeyException.class,
            SQLIntegrityConstraintViolationException.class})
    public JsonVO<String> sqlConstraintViolationHandler(Exception e) {
        SQLIntegrityConstraintViolationException sqlEx = null;

        if (e instanceof DuplicateKeyException) {
            sqlEx = (SQLIntegrityConstraintViolationException) e.getCause();
        } else if (e instanceof SQLIntegrityConstraintViolationException) {
            sqlEx = (SQLIntegrityConstraintViolationException) e;
        }

        if (sqlEx != null) {
            return handleSQLIntegrity(sqlEx);
        }
        return JsonVO.create("数据库约束冲突", ResultStatus.PARAMS_INVALID);
    }

    private JsonVO<String> handleSQLIntegrity(SQLIntegrityConstraintViolationException e) {
        String errorMsg = e.getMessage();
        String duplicateValue = "";
        String constraintName = "";

        // 提取重复值 (示例：Duplicate entry '1720210928263000431')
        if (errorMsg.contains("Duplicate entry")) {
            int start = errorMsg.indexOf("'") + 1;
            int end = errorMsg.indexOf("'", start);
            if (start > 0 && end > start) {
                duplicateValue = errorMsg.substring(start, end);
            }
        }

        // 提取约束名称 (示例：for key 'room_renovation.PRIMARY')
        if (errorMsg.contains("for key")) {
            int start = errorMsg.lastIndexOf("'");
            if (start > 0) {
                // 获取最后一个单引号后面的内容
                String tail = errorMsg.substring(start + 1);
                // 去除可能的尾随引号
                constraintName = tail.replace("'", "").trim();
            }
        }

        // 针对主键冲突的特殊处理
        if (constraintName.endsWith(".PRIMARY")) {
            return JsonVO.create("主键重复: " + duplicateValue + " 已存在", ResultStatus.PARAMS_INVALID);
        }

        // 其他唯一约束冲突的通用处理
        return JsonVO.create("数据冲突: " + constraintName + " 主键重复: " + duplicateValue,
                ResultStatus.PARAMS_INVALID);
    }

    //新增资源不存在异常处理
    @ExceptionHandler(ResourceNotFoundException.class)
    public JsonVO<String> handleResourceNotFound(ResourceNotFoundException e) {
        return JsonVO.create(e.getMessage(), ResultStatus.PARAMS_INVALID);
    }
}