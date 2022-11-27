# MyShell-Project
Operating Systems course myShell project   

* Shell komut satırı “myshell >>” olarak görülmelidir

* “exit” komutu girilene kadar çıkış olamaz. Her seferinde “myshell>>” olarak yeni komut satırına izin
vermelidir. 

* Eğer shellde olmayan bir komut, hatalı bir komut girilmişse(parametre hatası) ya da çağırılan
programlarda bir hata olduğunda “yanlis bir komut girdiniz” yazmalı ve myshell tekrar komut alabilir
hale gelmelidir.

* “bash” komutu girildiğinde sistemdeki bash programı çağırılmalıdır ve bashteki normal işlemler
yapılabilmelidir. Bu bash’e exit yazılana kadar diğer ana prosess beklemelidir. 
- myshell>>bash
- bash>>echoxxx
- xxx
- bash>>exit
- myshell>>

* “cat yazi...” çıktı: “cat:yazi...” 
* “clear” ekran temizler. 
* “ls” klasör içesindeki dosyaları gösterir.

* “execx” isminde “-t times program” parameter alan bir program yazılmalıdır. Bu program verilen
programın girilen adet kadar artarda çalıştırmalıdır. Çalışma arka planda olmalı myshell devam etmelidir. Program sağında kalan parametreler alt programa parametre olarak geçmelidir. Execx her bir çocuk porses oluşturduğunda prosesin işini bitirmesini beklemelidir.
- myshell>>execx-t3wriref
- myshell>> execx -t 3 wriref -f myfile

* “writef” isimli bir program yazılmalıdır. Bu program -f “file name” almalıdır. Eğer parameter olarak
verilen dosya varsa “append” yani sonuna ekleme yapmalı, eğer yoksa dosyayı oluşturup içine
yazmalıdır. Dosya içine system saatini, pid ve ppid değerini tek satır halinde yazmalıdır. 

