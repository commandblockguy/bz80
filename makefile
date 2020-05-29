rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))
includes = $(call rwildcard,.,*.h *.pbasic)

all: bin bin/bz80.8xp

bin:
	mkdir bin 

bin/bz80.8xp: bin/bz80.ibasic
	./tokenize bin/bz80.ibasic bin/bz80 BZ80

bin/bz80.ibasic: ${includes}
	gcc -x c-header -undef -P -E main.pbasic -o bin/bz80.ibasic

clean:
	-rm -r bin
	echo ${includes}