# 42-C-ssl_md5

MD5:
break down: --brief http://infohost.nmt.edu/~sfs/Students/HarleyKozushko/Presentations/MD5.pdf
-- more info https://tools.ietf.org/html/rfc1321.html
general: https://en.wikipedia.org/wiki/MD5

problem:
if after deal with str, the following is str, is fine. if it is a file, is fine. but it can not go back to str any more.
00: ./ft_ssl md5 -s "foo" -s "foo" test_pr.txt
MD5 ("foo") = acbd18db4cc2f85cedef654fccc4a4d8
MD5 ("foo") = acbd18db4cc2f85cedef654fccc4a4d8
MD5 (test_pr.txt) = c5e433c1dbd7ba01e3763a9483e74b04

01: ./ft_ssl md5 -s "foo" test_pr.txt -s "foo"
MD5 ("foo") = acbd18db4cc2f85cedef654fccc4a4d8
MD5 (test_pr.txt) = c5e433c1dbd7ba01e3763a9483e74b04
md5: -s: No such file or directory
md5: foo: No such file or directory

02: md5 -sp "foo" #after 's' flag, it is a str right after it
MD5 ("p") = 83878c91171338902e0fe0fb97a8c47a
md5: foo: No such file or directory

03:
md5 -s 'foo' == echo -n 'foo' | md5 // w/o "\n" & -s see everthing as char,
	even \n
md5 -s 'foo' == md5 -sfoo
md5 -r -s foo == md5 -rsfoo but not md5 -s -r foo
md5 test_foo.txt == echo "foo\n" | md5 // txt file has 2 \n
echo 'foo' | md5 // is with '\n'

04:


steps for md5:
1. handle the flags
2. validate files (empty)
3. open file, read file,
3.1 use gnl to count number of characters written,to get size in char (nbr of char * 4)
3.2 when lenght is less than 448, add to 448. more than 448, add to 512 then plus 448.
the content of the file need to be stored in a str. add unsigned char 128 for start. then NULL
