# c-oyun-satis-otomasyonu
C programlama dili ile geliştirilmiş oyun satış otomasyonu projesi. Oyun yönetimi, satış işlemleri, stok takibi ve dosya tabanlı veri saklama özelliklerini içermektedir.

# 🎮 Oyun Satış Otomasyonu

## 📌 Proje Hakkında

Oyun Satış Otomasyonu, C programlama dili kullanılarak geliştirilmiş konsol tabanlı bir otomasyon sistemidir. Bu proje, kullanıcıların sisteme üye olabilmesi, giriş yapabilmesi, oyunları görüntüleyebilmesi ve satın alma işlemlerini gerçekleştirebilmesi amacıyla geliştirilmiştir. Ayrıca sistem içerisinde yönetici paneli bulunmakta olup oyun ekleme, silme ve listeleme gibi işlemler gerçekleştirilebilmektedir.

Proje geliştirilirken temel programlama kavramları, dosya işlemleri, yapı (struct) kullanımı, fonksiyonlar ve kullanıcı yetkilendirme mekanizmaları uygulanmıştır. Veriler dosyalar üzerinde saklanarak kalıcı veri yönetimi sağlanmıştır.

---

# 🎯 Projenin Amacı

Bu projenin temel amacı;

* C programlama dilinde uygulama geliştirme becerilerini artırmak,
* Dosya işlemlerini kullanarak kalıcı veri saklama mantığını öğrenmek,
* Kullanıcı ve yönetici rollerini içeren bir otomasyon sistemi geliştirmek,
* Menü tabanlı uygulama tasarımını uygulamak,
* Gerçek hayatta kullanılabilecek basit bir satış sistemi oluşturmak,

olarak belirlenmiştir.

---

# ⚙️ Kullanılan Teknolojiler

* C Programlama Dili
* Struct Yapıları
* Fonksiyonlar
* Dosya İşlemleri (File Handling)
* Konsol Arayüzü
* Kullanıcı Doğrulama Sistemi
* Veri Yönetimi

---

# 👤 Kullanıcı İşlemleri

Sisteme kayıt olan kullanıcılar aşağıdaki işlemleri gerçekleştirebilmektedir:

### ✅ Üye Olma

Yeni kullanıcılar sisteme kayıt oluşturabilir.

### ✅ Giriş Yapma

Kayıtlı kullanıcılar kullanıcı adı ve şifre bilgileri ile sisteme giriş yapabilir.

### ✅ Oyunları Listeleme

Sistemde bulunan tüm oyunlar görüntülenebilir.

### ✅ Oyun Arama

Kullanıcılar istedikleri oyunu sistem içerisinde arayabilir.

### ✅ Oyun Satın Alma

Mevcut oyunlar satın alınabilir ve kullanıcının satın aldığı oyunlar listesine eklenir.

### ✅ Satın Alınan Oyunları Görüntüleme

Kullanıcı daha önce satın aldığı oyunları görüntüleyebilir.

### ✅ Oyun İade Etme

Satın alınan oyunlar sistem üzerinden iade edilebilir.

---

# 🔐 Yönetici İşlemleri

Yönetici hesabına sahip kullanıcılar aşağıdaki işlemleri gerçekleştirebilir:

### ✅ Oyun Ekleme

Sisteme yeni oyunlar eklenebilir.

### ✅ Oyun Silme

Mevcut oyunlar sistemden kaldırılabilir.

### ✅ Oyun Listeleme

Sistemde kayıtlı tüm oyunlar görüntülenebilir.

### ✅ Oyun Arama

Belirli oyunlar hızlı şekilde aranabilir.

### ✅ Oyun Yönetimi

Sistemde bulunan oyunların kontrolü ve yönetimi sağlanabilir.

---

# 💾 Veri Saklama Yapısı

Projede veriler dosyalar üzerinde tutulmaktadır.

### Kullanıcı Verileri

Kullanıcı bilgileri:

* Kullanıcı Adı
* Şifre
* Kullanıcı Bilgileri

veri dosyasında saklanmaktadır.

### Oyun Verileri

Oyunlara ait bilgiler:

* Oyun Adı
* Oyun Fiyatı
* Oyun Bilgileri

ayrı dosyalarda tutulmaktadır.

### Satın Alma Verileri

Kullanıcıların satın aldığı oyunlar kayıt altına alınmaktadır.

Bu yapı sayesinde program kapatılsa bile veriler korunmaktadır.

---

# 🧠 Projede Kullanılan Programlama Konuları

Bu proje geliştirilirken aşağıdaki konular aktif olarak kullanılmıştır:

* Değişkenler
* Karar Yapıları (if-else)
* Döngüler (for, while)
* Diziler
* Fonksiyonlar
* Struct Yapıları
* Pointer Kullanımı
* Dosya İşlemleri
* Menü Tabanlı Programlama
* Kullanıcı Yetkilendirme
* Veri Yönetimi

---

# 📸 Ekran Görüntüleri

Bu bölümde programın çalışmasına ait ekran görüntüleri yer almaktadır.

## Açılış Ekranı

![Açılış](C%20Oyun%20Satis%20Otomasyonu/screenshots/Acilis.png)

## Ana Menü

![Ana Menü](C%20Oyun%20Satis%20Otomasyonu/screenshots/AnaMenu.png)

## Kullanıcı Kayıt Ekranı

![Kayıt](C%20Oyun%20Satis%20Otomasyonu/screenshots/kayit.png)

![Kayıt](C%20Oyun%20Satis%20Otomasyonu/screenshots/kayit2.png)

## Kullanıcı Girişi

![Kullanıcı Girişi](C%20Oyun%20Satis%20Otomasyonu/screenshots/giris1.png)

![Kullanıcı Girişi](C%20Oyun%20Satis%20Otomasyonu/screenshots/giris2.png)

## Kullanıcı Profili

![Profil](C%20Oyun%20Satis%20Otomasyonu/screenshots/profil.png)

## Oyun Listeleme

![Oyun Listesi](C%20Oyun%20Satis%20Otomasyonu/screenshots/oyunListesi.png)

## Oyun Satın Alma

![Oyun Satın Alma](C%20Oyun%20Satis%20Otomasyonu/screenshots/oyunSatinAlma.png)

## Yönetici Paneli

![Yönetici Paneli](C%20Oyun%20Satis%20Otomasyonu/screenshots/yoneticiPanel.png)

---

# 🚀 Kazanımlar

Bu proje sayesinde;

* C programlama dili bilgisi geliştirilmiştir.
* Dosya işlemleri konusunda deneyim kazanılmıştır.
* Veri yönetimi mantığı öğrenilmiştir.
* Kullanıcı-yönetici yetkilendirme sistemi geliştirilmiştir.
* Gerçek bir otomasyon sisteminin temel yapısı oluşturulmuştur.
* Yazılım geliştirme süreçleri hakkında uygulamalı deneyim elde edilmiştir.

---

# 👨‍💻 Geliştirici Ekibi

Bu proje ekip çalışması kapsamında geliştirilmiştir.

### Takım Üyeleri

* **Elif Karacam** – Bilgisayar Programcılığı Öğrencisi
* **Ayşe Yılmaz** – Bilgisayar Programcılığı Öğrencisi
* **Merve Nur Şen** – Bilgisayar Programcılığı Öğrencisi

### Proje Hakkında

Oyun Satış Otomasyonu projesi, C programlama dili kullanılarak ekip çalışması kapsamında geliştirilmiştir. Proje sürecinde analiz, tasarım, kodlama, test ve hata giderme aşamaları takım üyeleri tarafından ortaklaşa yürütülmüştür.

Bu çalışma sayesinde ekip üyeleri dosya işlemleri, veri yönetimi, kullanıcı yetkilendirme sistemleri ve konsol tabanlı uygulama geliştirme konularında deneyim kazanmıştır.

---

# 📄 Lisans

Bu proje eğitim ve portfolyo amaçlı geliştirilmiştir.
