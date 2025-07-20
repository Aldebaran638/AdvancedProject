FROM openjdk:8
MAINTAINER 01star
ADD target/comm-j2-orgmanager-1.0.0-SNAPSHOT.jar app-j2-orgmanager.jar
ENV JAVA_OPTS="-Xms256m -Xmx256m"
ENV SPRING_ARGS=""
RUN echo "JAVA_OPTS=" $JAVA_OPTS
CMD java $JAVA_OPTS -jar app-j2-orgmanager.jar --logging.file.path=/tmp/logs/spring-boot $SPRING_ARGS