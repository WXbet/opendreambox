# Mandatory
Compiler: gcc **6.5.0**
Python: **2.7.17** + **3.6.9**

Working with latest Ubuntu 18.04.6 LTS and the following packages:
```
sudo apt-get install git build-essential diffstat texi2html texinfo subversion chrpath cvs gawk gettext-lint autopoint gcc-multilib gcc-6 g++-6 gcc-6-multilib file help2man python3-distutils
```

Set gcc-6 as default compiler:
```
for gv in {6..15}; do
    ( which gcc-$gv &>/dev/null ) && { echo "Adding gcc-$gv"; \
    sudo update-alternatives --install /usr/bin/gcc  gcc  $(which gcc-$gv) $gv \
                             --slave   /usr/bin/g++  g++  $(which g++-$gv) \
                             --slave   /usr/bin/gcov gcov $(which gcov-$gv); }
done

sudo update-alternatives --set gcc /usr/bin/gcc-6
```

This is a collection of layers for the opendreambox distribution.

Documentation is available in doc/.

Maintainers of this branch:

  Andreas Monzner <ghost@opendreambox.org>
  Andreas Oberritter <obi@opendreambox.org>
  Stephan Reichholf <reichi@opendreambox.org>

Please send patches or pull requests to patches@opendreambox.org.

When sending single patches, please use something like
'git send-email -M -1 --to patches@opendreambox.org' to let git send it,
or 'git format-patch -M -1' and send the resulting file as attachment.
