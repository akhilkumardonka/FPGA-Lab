How To
======

Build on ARM with 4bit LCD mode
----------

Initialize Environment:

::
  
  get_qorc

use your alias created in :code:`.bashrc` file, for me :code:`alias get_qorc='. $HOME/qorc-sdk/envsetup.sh'`.


make binary and flash to vaman board (in flash mode)
--------

From the project root dir, execute:

::
  
  make -C m4/GCC_Project/ && qfprog --port /dev/ttyACM0 --m4app m4/GCC_Project/output/bin/m4.bin --appfpga top.bin --mode m4-fpga


LCD Pin Connections
--------

| LCD Pin | Vaman Pin|
| ------- | -------- |
|   D4    |    6     |
|   D5    |    8     |
|   D6    |   10     |
|   D7    |   12     |
|   RS    |    2     |
|   EN    |    4     |
