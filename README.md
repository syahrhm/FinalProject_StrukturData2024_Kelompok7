# FinalProject_StrukturData2024_Kelompok7

## Kelompok 7
## Struktur Data-Final Project
## Anggota Kelompok

| NRP        | Nama                            |
|:----------:|:-------------------------------:|
| 5027231056 | Aisha Ayya Ratiandari           |
| 5027231076 | Syela Zeruya                    |
| 5027231072 | Aisyah Rahmasari                |


### IMPLEMENTASI

1. Class & Object:
- Terdapat beberapa class seperti Transportation, Airplane, Train, Bus, Ship, City, dan Booking.
- Objek-objek dari class-class ini dibuat dan digunakan dalam program utama.

2. Attribute / Property & Method / Behavior:
- Setiap class memiliki atribut-atribut (misalnya name, capacity, cost) dan metode-metode (seperti displayInfo, getCapacity, reduceCapacity, increaseCapacity, getCost, updateTicketCount, dll.).

3. Constructor:
- Setiap class memiliki constructor untuk menginisialisasi objek-objeknya (Transportation, Airplane, Train, Bus, Ship, City, Booking).

4. Setter & Getter:
- Terdapat method getter untuk mengakses nilai atribut (seperti getName, getCapacity, getCost, dll.) dan setter yang tidak secara eksplisit didefinisikan tetapi diimplementasikan melalui method lain seperti reduceCapacity dan increaseCapacity.

5. Encapsulation:
- Atribut-atribut pada class umumnya di-declare sebagai private dan diakses melalui method public seperti getter dan setter. Contohnya adalah name, capacity, dan cost pada berbagai class seperti Airplane, Train, Bus, dan Ship.

6. Inheritance:
- Terdapat pewarisan dari class dasar Transportation ke class-class turunannya (Airplane, Train, Bus, Ship). Misalnya, class Airplane mewarisi method-method dari Transportation.

7. Overriding:
- Metode displayInfo, getCapacity, reduceCapacity, increaseCapacity, getCost dari class Transportation di-override di class turunannya seperti Airplane, Train, Bus, dan Ship.

8. Abstraction:
- Transportation sebagai kelas abstrak memiliki method abstrak displayInfo, getCapacity, reduceCapacity, increaseCapacity, getCost yang diimplementasikan oleh subclass-subclassnya tanpa detail implementasi spesifik di kelas Transportation itu sendiri.

9. Polymorphism:
- Polimorfisme terlihat pada penggunaan pointer unik (unique_ptr) untuk objek Transportation, yang dapat merujuk pada objek dari class turunannya (Airplane, Train, Bus, Ship) dan memanggil method-methodnya seperti displayInfo, getCapacity, dan lain-lain tanpa perlu mengetahui tipe spesifik objek tersebut.
