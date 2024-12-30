# Schedule
https://pdos.csail.mit.edu/6.S081/2024/schedule.html

# Repo
git clone git://g.csail.mit.edu/xv6-labs-2024

# Playlist 2020
https://youtube.com/playlist?list=PLTsf9UeqkReZHXWY9yJvTwLJWYYPcKEqK

# Install
sudo apt-get install git build-essential gdb-multiarch qemu-system-misc gcc-riscv64-linux-gnu binutils-riscv64-linux-gnu
make qemu
exit - ctrl+a + x

# Tests
./grade-lab-util sleep

make GRADEFLAGS=sleep grade