@echo qemu-system-i386 -d int -m 2 -boot d -kernel bin/kernel.elf -serial file:Qemu_log.log -no-reboot
@H:\qemu\qemu-system-i386.exe -d int -m 2 -boot d -cdrom main\iso\boot.iso -hda H:\51.vhd -serial file:Qemu_log.log -no-reboot
@pause