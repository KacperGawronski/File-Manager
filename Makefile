CPPSTATIC=$(shell find -name "*.cpp"|sed 's/.cpp/.o/g'|sed 's/^\.\///g')
HEADERS=$(shell find -name "*.h"|sed 's/\.\///g')

all:	target
	g++ --std="c++14" $(shell pkg-config --cflags glibmm-2.4 gtkmm-3.0) -Bstatic $(CPPSTATIC) $(shell pkg-config --libs glibmm-2.4 gtkmm-3.0) -o main
target:	$(CPPSTATIC)
.SUFFIXES:	.o .cpp .h


depend: .depend

.depend: $(HEADERS)
	rm -f ./.depend
	$(CC) $(CFLAGS) -MM $^ -MF  ./.depend;

include .depend

.cpp.o:
	g++ -c --std="c++14" $(shell pkg-config --cflags glibmm-2.4 gtkmm-3.0) $< -o $@ $(shell pkg-config --libs glibmm-2.4 gtkmm-3.0)

clearo:
	rm $(CPPSTATIC)

clear: clearo
	rm main
