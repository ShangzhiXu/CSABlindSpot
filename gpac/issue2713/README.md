Link: https://github.com/gpac/gpac/issues/2647 <br/>
This bug is caused by unsufficent sanitization

The target buffer is of size 33<br>
![image](https://github.com/ShangzhiXu/CSABlindSpot/assets/63028857/9cea0a01-ca02-4c93-9a76-78166ad88128)
<br/><br>
There is a sanitizer trying to filter out string bigger than 32 to be copied to the buffer, in file `gpac/src/filters
/mux_isom.c`,like this : <br/>
![image](https://github.com/ShangzhiXu/CSABlindSpot/assets/63028857/75191578-2e01-4173-b924-3c1f319e1b15)

<br>
However, this sanitization is enough for the  `memcpy` , but not for `strcpy`. Because `strcpy` will copy 32 bytes of chars and a '\0' to the target, and this lead to the buffer overflow.
<br>

However, CSA cannot find this bug. But when we use a simple example, CSA can detect the bug in the example. Which means this false negtive is caused by the complexity of string operation in gpac. 
![image](https://github.com/ShangzhiXu/CSABlindSpot/assets/63028857/40fc7eb7-e447-4b0b-b9a8-198f2c2c2668)
![image](https://github.com/ShangzhiXu/CSABlindSpot/assets/63028857/649e1aeb-5378-46b5-979c-77b2ee5d30ab)

Actually, the variable `comp_name` may have hundreds of possible values, combined with hundreds of different paths, which make it hard for CSA to calculate.

![image](https://github.com/ShangzhiXu/CSABlindSpot/assets/63028857/c4e6ea1c-f53b-4a9e-a3a9-4edb057584e5)
