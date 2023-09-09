# genimage  

## what's genimage  
genimage is a tool to generate multiple filesystem and flash/disk images from a given root filesystem tree. genimage is intended to be run in a fakeroot environment. It also supports creating flash/disk images out of different file-system images and files.  

## compile genimage from source
```
git clone https://github.com/pengutronix/genimage.git

```

## sdcard image file structure
```
.
├── 0_gpt-table_offset_5M
├── 1_boot0_offset_8K
├── 2_boot_package_offset_16793600
│   ├── 20_u-boot
│   ├── 21_optee
│   └── 22_dtb
├── 3_boot_resource_offset_32M
│   └── bootlogo.bmp
├── 4_env.fex
├── 5_env_redund.fex
├── 6_boot.img
└── 7_rootfs.img
```