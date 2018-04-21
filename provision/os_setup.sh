# FIXME: Hay un problema con Ubuntu 17.10 (Artful Aardvark).
# Si actualizan el box; revisar!
# Workaround https://bugs.launchpad.net/cloud-images/+bug/1726818 sino el root file system pesa 2GB <.<
echo Expandiendo el root file system
sudo resize2fs /dev/sda1

echo Actualizando el Linux
apt -y update

apt -y install build-essential git lynx gdb valgrind python-pip

pip install gdbgui --upgrade

update-locale LANG=en_US.UTF-8 LANGUAGE=en_US.UTF-8 LC_ALL=en_US.UTF-8