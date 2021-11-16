#设置编译器
CC=gcc

#读取列出当前目录下的文件夹
SUBDIRS=$(shell ls -l | grep ^d | awk '{print $$9}')

#记住当前工程的根目录路径
ROOT_DIR=$(shell pwd)

#获取当前目录下的c文件集，放在变量CUR_SOURCE中
CUR_SOURCE=${wildcard *.c}

#将对应的c文件名转为o文件后放在下面的CUR_OBJS变量中
CUR_OBJS=${patsubst %.c, %.o, $(CUR_SOURCE)}

#将以下变量导出到子shell中，本次相当于导出到子目录下的makefile中
export CC  ROOT_DIR

#注意这里的顺序，需要先执行SUBDIRS最后才能是DEBUG
all:$(SUBDIRS) $(CUR_OBJS) app

#递归执行子目录下的makefile文件，这是递归执行的关键
$(SUBDIRS):ECHO
	make -C $@
ECHO:
	@echo $(SUBDIRS)
	
#将c文件编译为o文件，并放在指定放置目标文件的目录中即OBJS_DIR
$(CUR_OBJS):%.o:%.c
	$(CC) -c $^ -o $(ROOT_DIR)/$@
	
#将o文件进行链接为app	
app: main.o add.o sub.o
	$(CC) -o $@ $^
	@echo "build done!....."
clean:
	@rm *.o app
	@echo "remove sussced!....."

