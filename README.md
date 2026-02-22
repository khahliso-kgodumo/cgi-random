# CGI (Common Gateway Interface)

CGI is an interface specification that enables web servers to execute external programs or scripts

# Get a local copy
`
git clone https://github.com/khahliso-kgodumo/cgi-random.git
`
# Compile the source code
`
g++ -std=c++11 -Wall -Wextra -g main.cpp -o practical-1.cgi
`
# Give execution permissions
`
chmod +x practical-1.cgci
`

# Where to place files?
`
sudo mv wrong.html /var/www/html/cos332-html
sudo mv wrong.html /var/www/html/cos332-html
sudo mv beautiful.css /var/www/html/cos332-css
sudo mv practical-1.cgi /usr/lib/cgi-bin
`

# How To Access
- Open your web browser
- In the URL input field enter <ip-address>/cgi-bin/practical-1.cgi
