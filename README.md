

<p>

I am trying to build the project so that it does not depend on any extra Python shared libraries (.so files) or external Raylib installations on the system—everything should be bundled and self-contained within the project.

[gcLib_GnuLinux.so]->[gcLib/__init__.py]->[gcEngine.py]->[main.py]

[gcRunner] [main.py]


</p>



ldd gcRunner
<p>

        linux-vdso.so.1 (0x00007fa8bfd7a000)
        libpython3.13.so.1.0 => /SSD/Github/GnuChanGE/src/Engine/./Python/lib/libpython3.13.so.1.0 (0x00007fa8bf600000)
        libm.so.6 => /usr/lib/libm.so.6 (0x00007fa8bfc80000)
        libGL.so.1 => /usr/lib/libGL.so.1 (0x00007fa8bfc0d000)
        libc.so.6 => /usr/lib/libc.so.6 (0x00007fa8bf200000)
        /lib64/ld-linux-x86-64.so.2 => /usr/lib64/ld-linux-x86-64.so.2 (0x00007fa8bfd7c000)
        libGLdispatch.so.0 => /usr/lib/libGLdispatch.so.0 (0x00007fa8bf587000)
        libGLX.so.0 => /usr/lib/libGLX.so.0 (0x00007fa8bfbd9000)
        libX11.so.6 => /usr/lib/libX11.so.6 (0x00007fa8bf42c000)
        libxcb.so.1 => /usr/lib/libxcb.so.1 (0x00007fa8bfbac000)
        libXau.so.6 => /usr/lib/libXau.so.6 (0x00007fa8bf427000)
        libXdmcp.so.6 => /usr/lib/libXdmcp.so.6 (0x00007fa8bf41f000)

</p>



<p>

[/SSD/Github/GnuChanGE/src/Engine] -| strace -e openat ./gcRunner

openat(AT_FDCWD, "/SSD/Github/GnuChanGE/src/Engine/Python/lib/glibc-hwcaps/x86-64-v3/libpython3.13.so.1.0", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/SSD/Github/GnuChanGE/src/Engine/Python/lib/glibc-hwcaps/x86-64-v2/libpython3.13.so.1.0", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/SSD/Github/GnuChanGE/src/Engine/Python/lib/libpython3.13.so.1.0", O_RDONLY|O_CLOEXEC) = 3
openat(AT_FDCWD, "/SSD/Github/GnuChanGE/src/Engine/Python/lib/libm.so.6", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
openat(AT_FDCWD, "/usr/lib/libm.so.6", O_RDONLY|O_CLOEXEC) = 3
openat(AT_FDCWD, "/SSD/Github/GnuChanGE/src/Engine/Python/lib/libGL.so.1", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/usr/lib/libGL.so.1", O_RDONLY|O_CLOEXEC) = 3
openat(AT_FDCWD, "/SSD/Github/GnuChanGE/src/Engine/Python/lib/libc.so.6", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/usr/lib/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
openat(AT_FDCWD, "/usr/lib/libGLdispatch.so.0", O_RDONLY|O_CLOEXEC) = 3
openat(AT_FDCWD, "/usr/lib/libGLX.so.0", O_RDONLY|O_CLOEXEC) = 3
openat(AT_FDCWD, "/usr/lib/libX11.so.6", O_RDONLY|O_CLOEXEC) = 3
openat(AT_FDCWD, "/usr/lib/libxcb.so.1", O_RDONLY|O_CLOEXEC) = 3
openat(AT_FDCWD, "/usr/lib/libXau.so.6", O_RDONLY|O_CLOEXEC) = 3
openat(AT_FDCWD, "/usr/lib/libXdmcp.so.6", O_RDONLY|O_CLOEXEC) = 3
Kullanım: ./gcRunner script.py
+++ exited with 1 +++

</p>

ldd gcLib_GnuLinux.so 
<p>

        linux-vdso.so.1 (0x00007f9bda358000)
        libm.so.6 => /usr/lib/libm.so.6 (0x00007f9bda263000)
        libGL.so.1 => /usr/lib/libGL.so.1 (0x00007f9bda1f0000)
        libc.so.6 => /usr/lib/libc.so.6 (0x00007f9bd9600000)
        /usr/lib64/ld-linux-x86-64.so.2 (0x00007f9bda35a000)
        libGLdispatch.so.0 => /usr/lib/libGLdispatch.so.0 (0x00007f9bd9987000)
        libGLX.so.0 => /usr/lib/libGLX.so.0 (0x00007f9bda1be000)
        libX11.so.6 => /usr/lib/libX11.so.6 (0x00007f9bd982c000)
        libxcb.so.1 => /usr/lib/libxcb.so.1 (0x00007f9bd95d3000)
        libXau.so.6 => /usr/lib/libXau.so.6 (0x00007f9bda1b7000)
        libXdmcp.so.6 => /usr/lib/libXdmcp.so.6 (0x00007f9bda1af000)

</p>