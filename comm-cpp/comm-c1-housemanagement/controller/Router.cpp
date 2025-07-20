/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/03 14:58:34

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "Router.h"
#include "ApiHelper.h"
//#include "HouseList/HouseListController.h"
#include "HouseName/HouseNameController.h"
#include "HouseDetail/HouseDetailController.h"
#include "HouseSelect/HouseSelectController.h"
#include "HouseList/HouseListController.h"
#include "floor/FloorController.h"
#include "house/HouseController.h"
#include "housefile/HouseFileController.h"
#include "car/CarController.h"
#include "owner/OwnerController.h"

#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "file/FileController.h"
#include "UnitController/UnitController.h"
#include "ws/WSController.h"
#endif
#include "UnitController/UnitController.h"

// ��������˹ر�Swagger�ĵ���
#ifdef CLOSE_SWAGGER_DOC
// �򻯰󶨿������궨��
#define ROUTER_SIMPLE_BIND(__CLASS__) \
router->addController(__CLASS__::createShared())
#else
// �򻯰󶨿������궨��
#define ROUTER_SIMPLE_BIND(__CLASS__) \
BIND_CONTROLLER(docEndpoints, router, __CLASS__)
#endif

Router::Router(Endpoints* docEndpoints, HttpRouter* router)
{
	this->docEndpoints = docEndpoints;
	this->router = router;
}

void Router::initRouter()
{
#ifdef HTTP_SERVER_DEMO
	createSampleRouter();
#endif

	//#TIP :ϵͳ��չ·�ɶ��壬д���������
	//ROUTER_SIMPLE_BIND(HouseListController);
	//ROUTER_SIMPLE_BIND(HouseNameController); // ��������ע���¿�����
	ROUTER_SIMPLE_BIND(HouseDetailController);
	ROUTER_SIMPLE_BIND(HouseSelectController);
	ROUTER_SIMPLE_BIND(HouseListController);
	ROUTER_SIMPLE_BIND(HouseNameController);
	ROUTER_SIMPLE_BIND(UnitController);
	ROUTER_SIMPLE_BIND(FloorController);
	ROUTER_SIMPLE_BIND(HouseController);
	ROUTER_SIMPLE_BIND(HouseFileController);
	ROUTER_SIMPLE_BIND(CarController);
	ROUTER_SIMPLE_BIND(OwnerController);
}

#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	// ��ʾ��������
	ROUTER_SIMPLE_BIND(SampleController);
	// ���û�������
	ROUTER_SIMPLE_BIND(UserController);
	// ���ļ�������
	ROUTER_SIMPLE_BIND(FileController);

	// ��WebSocket������
	router->addController(WSContorller::createShared());
}
#endif

void Router::createUnitRouter()
{
	// �󶨵�Ԫ������
	ROUTER_SIMPLE_BIND(UnitController);

	//// ��WebSocket������
	//router->addController(WSContorller::createShared());
}

void Router::createFloorRouter() {
	//绑定Floor楼栋控制器
	ROUTER_SIMPLE_BIND(FloorController);



}

