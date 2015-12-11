update:
	clear
	echo Updating Website
	sudo rm -r /var/www/game.com/public_html/*
	sudo cp -r . /var/www/game.com/public_html
	echo Website Updated.

set-up:
	clear
	echo Setting-up Website
	sudo apt-get purge apache2
	sudo apt-get install apache2
	sudo mkdir -p /var/www/game.com/public_html
	sudo cp apache2.game.conf /etc/apache2/sites-available/game.com.conf
	sudo a2enmod include
	sudo a2ensite game.com.conf
	sudo a2dissite 000-default.conf
	sudo service apache2 restart
	sudo cp -r . /var/www/game.com/public_html
	echo Website Setup Done

take-down:
	clear
	echo Taking Down Website
	sudo rm /var/www/game.com
	sudo apt-get purge apache2
	echo Website Taken Down
