Merhaba arkadaşlar C/C++ dersleri devam ederken aynı zaman da vaktimin yettiğince directx11 anlatmaya çalışacağım.

Hemen giriş yapalım. Öncelikle directx öğrenmeye merak sardıysanız C/C++(OOP) programlamayı iyi bildiğinizi varsayıyorum.Bu derslerde herhangi bir C/C++ konusu bulunmayıp eksiklerinizi de tamamlamanızı öneririm.

Directx Nedir?
Directx, Microsoft’ un video oyunları başta olmak üzere çoklu ortam yazılımlarını rahat, hızlı ve uyumlu şekilde hazırlayabilmek için yarattığı bir API yazılım programlama arayüzüdür. Şu andaki en güncel resmi sürümü Directx12′ dir.

Evet Directx’ in ne olduğunu öğrendikten sonra Directx SDK’ yı kuralım. Windows 8 ve 10 kullananlar için SDK otomatik olarak kurulu gelir geri kalanınız ise şu linkden indirebilirsiniz.

Directx SDK

Ben projelerimi visual studio 2012 ortamında yazıyorum ve ona göre anlatacağım ama diğer sürümlerindede çok fazla farklılık olacağını sanmıyorum.

Kurulum

Öncelikle Visual Studio ortamını açıp File->New->Project diyerek yeni bir C++ projesi oluşturunuz.
Daha sonra “Solution Explorer” kısmında proje ismine sağ tıklayıp “Properties” kısmına tıklayın.
“Configuration” kısmını “Active(Debug)”, “Platform” ise “Active(Win32)” yapınız.
“Configuration Properties” kısmından “VC++ Directories” kısmına tıklayınız.
“Include Directories” kısmına gelin kenarda açılan oka tıklayıp edit kısmına basın.
Ekran Görüntüsü (44)

Üstteki “New Line” Kısmına tıklayın. Ve açılan kısımda … olan buton var ona basın.
Ekran Görüntüsü (45)

Ekran Görüntüsü (46)

Açılan dosya ekranından “C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include” yoluna gelip tamam deyin.
“VC++ Directories” kısmından “Library Directories” kısmına tıklayın ve aynı işlemi bu sefer şu yolla yapın. “C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Lib\x86” ve kurulumu tamamlayın.
Bir sonraki dersimizde Framework yapımıza ve win32 pencerimizi oluşturmamıza bakacağız.

Egzersiz

Örenk olarak SDK dosyası içerisindeki bazı kodları çalıştırıp bakabilirsiniz. \Samples\C++\Direct3D11\Tutorials