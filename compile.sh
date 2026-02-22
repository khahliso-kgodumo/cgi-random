g++ -std=c++11 -Wall -Wextra -g main.cpp -o practical-1
sudo chmod +x practical-1
echo "md5 hash : $(md5sum practical-1)"
# delete files
sudo rm /usr/lib/cgi-bin/practical-1
sudo rm /var/www/html/cos332-html/wrong.htm
sudo rm /var/www/html/cos332-html/right.htm
sudo rm /var/www/html/cos332-css/beautiful.css

# copy files
sudo cp wrong.htm /var/www/html/cos332-html/
sudo cp right.htm /var/www/html/cos332-html/
sudo cp beautiful.css /var/www/html/cos332-css
sudo mv practical-1 /usr/lib/cgi-bin
