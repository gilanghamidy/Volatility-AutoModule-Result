# Volatility module.c For All Linux Version
Volatility require kernel symbol to extract information from a memory dump. Unfortunately, the module.c provided in the Volatility tools is outdated for many kernel versions. Usually we need to copy-paste from the kernel source manually to solve the mismatch between those two. But this is time consuming and prone to human-error.

Therefore, we decided to develop a tool to extract kernel data structure automatically and generate the module.c that works for all kernel versions. The tool itself is not ready for public release as there's still some bug fixing and refactoring needed to make it ready to release. However, we already produced some working samples that you can try.

This works exactly like the original symbol generator in volatility/tools/linux source. Just run the makefile, and the symbol is generated for the kernel source you have. If you want to target some specific kernel source in a specific location, just modify the makefile and change the kernel source location.

## Known Issues
1. SLAB allocator structures is not enclosed by ifdef, hence it will appear in both SLAB or SLUB allocator
2. Kernel prior to 2.6.29 is not available due the kernel build script issue which prevents our tool to run (Looks like it will be unfixable and will require manual intervention)

## To Do
Publish the tools with acceptable quality of codes and documentations 

## Team
1. Gilang Mentari Hamidy (gilang@hamidy.net) - Original Developer
2. Davide Balzarotti (https://github.com/balzarot) - Main Supervisor
3. Fabio Pagani (https://github.com/pagabuc) - Supervisor
4. Andrea Oliveri (https://github.com/iridiumxor) - Supervisor

This project is a part of compulsory student project by Gilang Mentari Hamidy, a master's student of EURECOM, promo 2021

## License
Copyright 2020  Gilang Mentari Hamidy

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
