asd:
	FILES='find src -name *.c'
	echo "$$files"
compile:
	cp makefile src/
	cd src/; make compile_recur
	rm src/makefile
compile_recur:
	for object in *; \
	do \
		echo "$$object"
		if [ -d "$$object" ]; \
		then \
			cp makefile "$$object"; \
			cd "$$object"; \
			echo "$$object"; \
			make compile_recur; \
			rm makefile; \
		elif [ $$object |grep '*.c' ]; \
		then \
			gcc -c $$object; \
		fi; \
	done
run:
	cd bin;./Morte
install:
	sudo apt-get install libsdl2-dev # library that handels window creation and input
	sudo apt-get install libsdl2-mixer-dev
	sudo apt-get install libassimp-dev # library for importing 3d models
	git config --global user.email "Kpampusch@yahoo.com"
	git config --global user.name "NotSarcastic"
#	cd SDL
#	./configure
#	make
#	sudo make install
push:
	clear
	echo GitHub...
	git add .
	git commit -a
	git push
pull:
	clear
	git pull
update site:
	cd website
	make update website
	cd ../
start website:
	echo hi
	cd website
	make set-up website
	cd ../
end website:
	cd website
	make take-down website
	cd ../
goodbye:
	echo FAREWELL CRUEL WORLD
