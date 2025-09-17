** Fork info **

Fork of the BigSQL fork of pgadmin3-lts from allentc/pgadmin3-lts, functional
with PostgreSQL 15.

pgAdmin3 is Free Software released under the PostgreSQL License.


Tried on Ubuntu 24.04 LTS
------------------------
- Below are the instructions from allentc -
```
# apt-get install libwxgtk3.0-dev wx3.0-headers wxgtk3.0 wx3.0

# apt-get install libssh2-1 libssh2-1-dev libgcrypt20 libgcrypt20-dev libjson-perl libpq-dev #postgresql-15 postgresql-contrib-15 postgresql-client-15
# systemctl restart postgresql || true

$ bash bootstrap
$ ./configure --prefix=/opt/pgadmin3bigsql --with-libgcrypt --with-wx-version=3.0  CFLAGS=-fPIC CXXFLAGS=-fPIC #--with-pgsql=/usr/lib/postgresql/15 --without-sphinx-build
$ make -j8
$ sudo make install
```

If the package does not compile on account of WxWidgets, download and build WxWidgets. e.g. ./configure --with-gtk=2, and if wx-config is not found, point it to the right location in the configure file.

If "--with-sphinx-build" is specified in ./configure, then use the system sphinx-build binary. If this throws an error then compile with "--without-sphinx-build".
Errors with wxFONTWEIGHT_EXTRABOLD, in ./pgadmin/dlg/dlgMainConfig.cpp can be overcome by replacing the string with wxFONTWEIGHT_BOLD.
Errors in the function call StartStyling(0) in pgadmin/frm/frmQuery.cpp: call with StartStyling(0,0), i.e. with two args, instead of one.

Compilation was done with:
```
./configure --prefix=/usr/local/lib/pgadmin3-lts --with-libgcrypt --with-wx-version=3.0  CFLAGS=-fPIC CXXFLAGS=-fPIC --without-sphinx-build
make
make install
```
Finally, if you compiled WxWidgets from source, you may need to link the libraries.
In /usr/lib/x86_64-linux-gnu/: 
```
sudo ln -s /path/to/libwx_gtk2u_stc-3.0.so.0
sudo ln -s /path/to/libwx_gtk2u_aui-3.0.so.0
sudo ln -s /path/to/libwx_gtk2u_xrc-3.0.so.0
sudo ln -s /path/to/libwx_gtk2u_html-3.0.so.0
sudo ln -s /path/to/libwx_gtk2u_adv-3.0.so.0
sudo ln -s /path/to/libwx_gtk2u_core-3.0.so.0
sudo ln -s /path/to/libwx_baseu_xml-3.0.so.0
sudo ln -s /path/to/libwx_baseu_net-3.0.so.0
sudo ln -s /path/to/libwx_baseu-3.0.so.0
```
Finally, add a launcher for pgadmin3 in /usr/share/applications/ as pgadmin3.desktop.


