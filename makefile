rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))
includes = $(call rwildcard,src,*.h *.pbasic) $(call rwildcard,include,*.h *.pbasic)

all: bin bin/bz80.8xp

bin:
	mkdir bin

bin/bz80.8xp: bin/bz80.unprettified
	tivars_cli --iformat raw --input bin/bz80.unprettified --oformat varfile --output bin/bz80.8xp --type Program --name BZ80

bin/bz80.unprettified: bin/bz80.tokenized
	python3 unprettify.py bin/bz80.tokenized bin/bz80.unprettified

bin/bz80.tokenized: bin/bz80.ibasic
	tivars_cli --iformat readable --input bin/bz80.ibasic --oformat raw --output bin/bz80.tokenized --type Program

bin/bz80.ibasic: ${includes}
	gcc -Iinclude -x c-header -undef -P -E src/main.pbasic -o bin/bz80.ibasic

clean:
	-rm -r bin
