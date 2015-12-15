#Directx11' e Giriş

Merhaba arkadaşlar C/C++ dersleri devam ederken aynı zaman da vaktimin yettiğince directx11 anlatmaya çalışacağım.

Hemen giriş yapalım. Öncelikle directx öğrenmeye merak sardıysanız C/C++(OOP) programlamayı iyi bildiğinizi varsayıyorum.Bu derslerde herhangi bir C/C++ konusu bulunmayıp eksiklerinizi de tamamlamanızı öneririm.

##Directx Nedir?
Directx, Microsoft’ un video oyunları başta olmak üzere çoklu ortam yazılımlarını rahat, hızlı ve uyumlu şekilde hazırlayabilmek için yarattığı bir API yazılım programlama arayüzüdür. Şu andaki en güncel resmi sürümü Directx12′ dir.

Evet Directx’ in ne olduğunu öğrendikten sonra Directx SDK’ yı kuralım. Windows 8 ve 10 kullananlar için SDK otomatik olarak kurulu gelir geri kalanınız ise şu linkden indirebilirsiniz.

[Directx SDK](https://www.microsoft.com/en-us/download/details.aspx?id=6812)

Ben projelerimi visual studio 2012 ortamında yazıyorum ve ona göre anlatacağım ama diğer sürümlerindede çok fazla farklılık olacağını sanmıyorum.

##Kurulum

Öncelikle Visual Studio ortamını açıp File->New->Project diyerek yeni bir C++ projesi oluşturunuz.
Daha sonra “Solution Explorer” kısmında proje ismine sağ tıklayıp “Properties” kısmına tıklayın.
“Configuration” kısmını “Active(Debug)”, “Platform” ise “Active(Win32)” yapınız.
“Configuration Properties” kısmından “VC++ Directories” kısmına tıklayınız.
“Include Directories” kısmına gelin kenarda açılan oka tıklayıp edit kısmına basın.
![0](images/ders 1/Ekran-Görüntüsü-44-300x214.png)

Üstteki “New Line” Kısmına tıklayın. Ve açılan kısımda … olan buton var ona basın.
![0](images/ders 1/Ekran-Görüntüsü-45-300x212.png)

![0](images/ders 1/Ekran-Görüntüsü-46-300x214.png)

Açılan dosya ekranından “C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include” yoluna gelip tamam deyin.
“VC++ Directories” kısmından “Library Directories” kısmına tıklayın ve aynı işlemi bu sefer şu yolla yapın. “C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Lib\x86” ve kurulumu tamamlayın.
Bir sonraki dersimizde Framework yapımıza ve win32 pencerimizi oluşturmamıza bakacağız.

##Egzersiz

- Örnek olarak SDK dosyası içerisindeki bazı kodları çalıştırıp bakabilirsiniz. \Samples\C++\Direct3D11\Tutorials
