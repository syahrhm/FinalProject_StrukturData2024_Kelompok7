#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>
#include <memory>
#include <algorithm>

using namespace std;

// Abstract base class for Transportation
class Transportation {
protected:
    string name;
public:
    Transportation(const string& transportName) : name(transportName) {}
    virtual void displayInfo() const = 0; // Pure virtual method
    string getName() const { return name; }
    virtual int getCapacity(const string& companyName) const = 0;
    virtual void reduceCapacity(const string& companyName, int count) = 0;
    virtual void increaseCapacity(const string& companyName, int count) = 0;
    virtual int getCost(const string& companyName) const = 0;
    virtual ~Transportation() {}
};

class Airplane : public Transportation {
public:
    struct Airline {
        string name;
        int cost;
        int travelTime;
        int capacity;
    };
private:
    vector<Airline> airlines;
public:
    Airplane() : Transportation("Pesawat") {
        airlines = {
            {"Lion Indonesia", 1000000, 1, 180},
            {"Cityskapes", 1200000, 1, 150},
            {"Garuda Air", 1500000, 1, 200}
        };
    }
    void displayInfo() const override {
        for (const auto& airline : airlines) {
            cout << "Maskapai: " << airline.name << "\n"
                 << "Biaya: " << airline.cost << " IDR\n"
                 << "Waktu Tempuh: " << airline.travelTime << " jam\n"
                 << "Kapasitas: " << airline.capacity << " penumpang\n\n";
        }
    }
    int getCapacity(const string& companyName) const override {
        for (const auto& airline : airlines) {
            if (airline.name == companyName) {
                return airline.capacity;
            }
        }
        return 0;
    }
    void reduceCapacity(const string& companyName, int count) override {
        for (auto& airline : airlines) {
            if (airline.name == companyName) {
                airline.capacity -= count;
                break;
            }
        }
    }
    void increaseCapacity(const string& companyName, int count) override {
        for (auto& airline : airlines) {
            if (airline.name == companyName) {
                airline.capacity += count;
                break;
            }
        }
    }
    int getCost(const string& companyName) const override {
        for (const auto& airline : airlines) {
            if (airline.name == companyName) {
                return airline.cost;
            }
        }
        return 0;
    }
};

class Train : public Transportation {
public:
    struct TrainType {
        string name;
        int cost;
        int travelTime;
        int capacity;
    };
private:
    vector<TrainType> trains;
public:
    Train() : Transportation("Kereta") {
        trains = {
            {"Argo Sembrani", 100000, 11, 500},
            {"Argo Brawijaya", 120000, 12, 450},
            {"Taksakang", 80000, 13, 600}
        };
    }
    void displayInfo() const override {
        for (const auto& train : trains) {
            cout << "Kereta: " << train.name << "\n"
                 << "Biaya: " << train.cost << " IDR\n"
                 << "Waktu Tempuh: " << train.travelTime << " jam\n"
                 << "Kapasitas: " << train.capacity << " penumpang\n\n";
        }
    }
    int getCapacity(const string& companyName) const override {
        for (const auto& train : trains) {
            if (train.name == companyName) {
                return train.capacity;
            }
        }
        return 0;
    }
    void reduceCapacity(const string& companyName, int count) override {
        for (auto& train : trains) {
            if (train.name == companyName) {
                train.capacity -= count;
                break;
            }
        }
    }
    void increaseCapacity(const string& companyName, int count) override {
        for (auto& train : trains) {
            if (train.name == companyName) {
                train.capacity += count;
                break;
            }
        }
    }
    int getCost(const string& companyName) const override {
        for (const auto& train : trains) {
            if (train.name == companyName) {
                return train.cost;
            }
        }
        return 0;
    }
};

class Bus : public Transportation {
public:
    struct BusType {
        string name;
        int cost;
        int travelTime;
        int capacity;
    };
private:
    vector<BusType> buses;
public:
    Bus() : Transportation("Bis") {
        buses = {
            {"Rosalia Cantik", 300000, 10, 40},
            {"Rahayu", 250000, 12, 50},
            {"Trisakti", 200000, 14, 45}
        };
    }
    void displayInfo() const override {
        for (const auto& bus : buses) {
            cout << "Bis: " << bus.name << "\n"
                 << "Biaya: " << bus.cost << " IDR\n"
                 << "Waktu Tempuh: " << bus.travelTime << " jam\n"
                 << "Kapasitas: " << bus.capacity << " penumpang\n\n";
        }
    }
    int getCapacity(const string& companyName) const override {
        for (const auto& bus : buses) {
            if (bus.name == companyName) {
                return bus.capacity;
            }
        }
        return 0;
    }
    void reduceCapacity(const string& companyName, int count) override {
        for (auto& bus : buses) {
            if (bus.name == companyName) {
                bus.capacity -= count;
                break;
            }
        }
    }
    void increaseCapacity(const string& companyName, int count) override {
        for (auto& bus : buses) {
            if (bus.name == companyName) {
                bus.capacity += count;
                break;
            }
        }
    }
    int getCost(const string& companyName) const override {
        for (const auto& bus : buses) {
            if (bus.name == companyName) {
                return bus.cost;
            }
        }
        return 0;
    }
};

class Ship : public Transportation {
public:
    struct ShipType {
        string name;
        int cost;
        int travelTime;
        int capacity;
    };
private:
    vector<ShipType> ships;
public:
    Ship() : Transportation("Kapal") {
        ships = {
            {"Ferry Naik", 700000, 20, 300},
            {"Nusa Dharma", 800000, 22, 350},
            {"Titian Murni", 900000, 24, 400}
        };
    }
    void displayInfo() const override {
        for (const auto& ship : ships) {
            cout << "Kapal: " << ship.name << "\n"
                 << "Biaya: " << ship.cost << " IDR\n"
                 << "Waktu Tempuh: " << ship.travelTime << " jam\n"
                 << "Kapasitas: " << ship.capacity << " penumpang\n\n";
        }
    }
    int getCapacity(const string& companyName) const override {
        for (const auto& ship : ships) {
            if (ship.name == companyName) {
                return ship.capacity;
            }
        }
        return 0;
    }
    void reduceCapacity(const string& companyName, int count) override {
        for (auto& ship : ships) {
            if (ship.name == companyName) {
                ship.capacity -= count;
                break;
            }
        }
    }
    void increaseCapacity(const string& companyName, int count) override {
        for (auto& ship : ships) {
            if (ship.name == companyName) {
                ship.capacity += count;
                break;
            }
        }
    }
    int getCost(const string& companyName) const override {
        for (const auto& ship : ships) {
            if (ship.name == companyName) {
                return ship.cost;
            }
        }
        return 0;
    }
};

// Class representing a city
class City {
private:
    string name;
    string island;
public:
    City(const string& cityName, const string& cityIsland) : name(cityName), island(cityIsland) {}
    string getName() const { return name; }
    string getIsland() const { return island; }
};

// Class representing a booking
class Booking {
private:
    static int nextId;
    string id;
    string name;
    string transportType;
    string companyName;
    string destination;
    int ticketCount;
    int totalCost;
public:
    Booking(const string& userName, const string& transport, const string& company, const string& dest, int count, int cost)
        : name(userName), transportType(transport), companyName(company), destination(dest), ticketCount(count), totalCost(cost) {
        id = "BKG" + to_string(nextId++);
    }
    string getId() const { return id; }
    string getName() const { return name; }
    string getTransportType() const { return transportType; }
    string getCompanyName() const { return companyName; }
    int getTicketCount() const { return ticketCount; }
    int getTotalCost() const { return totalCost; }
    void updateTicketCount(int newCount, int costPerTicket) {
        totalCost = newCount * costPerTicket;
        ticketCount = newCount;
    }
    void displayBooking() const {
        cout << "ID Pemesanan: " << id << "\n"
             << "Nama: " << name << "\n"
             << "Jenis Transportasi: " << transportType << "\n"
             << "Perusahaan: " << companyName << "\n"
             << "Tujuan: " << destination << "\n"
             << "Jumlah Tiket: " << ticketCount << "\n"
             << "Total Biaya: " << totalCost << " IDR\n\n";
    }
};

int Booking::nextId = 1;

vector<string> getTransportOptions(const City* startCity, const City* endCity) {
    vector<string> options;
    if (startCity->getIsland() == "Jawa" && endCity->getIsland() == "Jawa") {
        options = {"Kereta", "Bis", "Kapal"};
    } else if (startCity->getIsland() == "Jawa" || endCity->getIsland() == "Jawa") {
        options = {"Bis", "Kapal", "Pesawat"};
    } else {
        options = {"Kapal", "Pesawat"};
    }
    return options;
}

unique_ptr<Transportation> createTransportation(const string& type) {
    if (type == "Pesawat") return make_unique<Airplane>();
    if (type == "Kereta") return make_unique<Train>();
    if (type == "Bis") return make_unique<Bus>();
    if (type == "Kapal") return make_unique<Ship>();
    return nullptr;
}

int main() {
    vector<City> cities = {
        {"Jakarta", "Jawa"},
        {"Jogja", "Jawa"},
        {"Surabaya", "Jawa"},
        {"Batam", "Luar Jawa"},
        {"Pontianak", "Luar Jawa"},
        {"Lombok", "Luar Jawa"}
    };

    vector<Booking> bookings;

    while (true) {
        cout << "\nMenu:\n"
             << "1. Membuat pemesanan\n"
             << "2. Update pemesanan\n"
             << "3. Hapus pemesanan\n"
             << "4. Menampilkan pemesanan yang ada\n"
             << "5. Exit\n"
             << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            string userName;
            cout << "Enter your name: ";
            cin.ignore();
            getline(cin, userName);

            int startCityIndex, endCityIndex;
            cout << "Select your starting city:\n";
            for (int i = 0; i < cities.size(); ++i) {
                cout << i + 1 << ". " << cities[i].getName() << "\n";
            }
            cout << "Enter your choice (1-" << cities.size() << "): ";
            cin >> startCityIndex;

            cout << "Select your destination city:\n";
            for (int i = 0; i < cities.size(); ++i) {
                cout << i + 1 << ". " << cities[i].getName() << "\n";
            }
            cout << "Enter your choice (1-" << cities.size() << "): ";
            cin >> endCityIndex;

            City* startCity = &cities[startCityIndex - 1];
            City* endCity = &cities[endCityIndex - 1];

            auto transportOptions = getTransportOptions(startCity, endCity);

            cout << "Pilih jenis transportasi:\n";
            for (int i = 0; i < transportOptions.size(); ++i) {
                cout << i + 1 << ". " << transportOptions[i] << "\n";
            }
            cout << "Enter your choice: ";
            int transportChoice;
            cin >> transportChoice;

            if (transportChoice < 1 || transportChoice > transportOptions.size()) {
                cout << "Pilihan tidak valid\n";
                continue;
            }

            string selectedTransport = transportOptions[transportChoice - 1];
            unique_ptr<Transportation> transport = createTransportation(selectedTransport);

            if (transport == nullptr) {
                cout << "Pilihan transportasi ini tidak tersedia.\n";
                continue;
            }

            transport->displayInfo();

            string companyName;
            cout << "Enter the company name from the above options: ";
            cin.ignore();
            getline(cin, companyName);

            int ticketCount;
            cout << "Enter the number of tickets: ";
            cin >> ticketCount;

            if (transport->getCapacity(companyName) < ticketCount) {
                cout << "Kapasitas tidak cukup.\n";
                continue;
            }

            int totalCost = transport->getCost(companyName) * ticketCount;
            transport->reduceCapacity(companyName, ticketCount);

            Booking newBooking(userName, selectedTransport, companyName, endCity->getName(), ticketCount, totalCost);
            bookings.push_back(newBooking);
            cout << "Pemesanan berhasil dilakukan! ID Pemesanan: " << newBooking.getId() << "\n";

        } else if (choice == 2) {
            string userName;
            cout << "Enter your name: ";
            cin.ignore();
            getline(cin, userName);

            // Update pemesanan
            string bookingId;
            cout << "Enter your booking ID: ";
            getline(cin, bookingId);

            auto it = find_if(bookings.begin(), bookings.end(), [&bookingId](const Booking& b) {
                return b.getId() == bookingId;
            });

            if (it == bookings.end()) {
                cout << "Pemesanan tidak ditemukan.\n";
                continue;
            }

            int newTicketCount;
            cout << "Enter new ticket count: ";
            cin >> newTicketCount;

            string transportType = it->getTransportType();
            unique_ptr<Transportation> transport = createTransportation(transportType);
            string companyName = it->getCompanyName();
            int currentTicketCount = it->getTicketCount();

            if (newTicketCount > currentTicketCount) {
                int additionalTickets = newTicketCount - currentTicketCount;
                if (transport->getCapacity(companyName) < additionalTickets) {
                    cout << "Gagal Melakukan Pemesanan.\n";
                    continue;
                }
                transport->reduceCapacity(companyName, additionalTickets);
            } else {
                int removedTickets = currentTicketCount - newTicketCount;
                transport->increaseCapacity(companyName, removedTickets);
            }

            int newTotalCost = transport->getCost(companyName) * newTicketCount;
            it->updateTicketCount(newTicketCount, transport->getCost(companyName));
            cout << "Pemesanan berhasil diperbarui! Total Biaya baru: " << newTotalCost << " IDR\n";

        } else if (choice == 3) {
            string userName;
            cout << "Enter your name: ";
            cin.ignore();
            getline(cin, userName);

            // Hapus pemesanan
            string bookingId;
            cout << "Enter your booking ID: ";
            getline(cin, bookingId);

            auto it = find_if(bookings.begin(), bookings.end(), [&bookingId](const Booking& b) {
                return b.getId() == bookingId;
            });

            if (it == bookings.end()) {
                cout << "Pemesanan tidak ditemukan.\n";
                continue;
            }

            cout << "Apakah Anda yakin ingin menghapus pemesanan ini? (yes/no): ";
            string confirmation;
            getline(cin, confirmation);

            if (confirmation == "yes") {
                string transportType = it->getTransportType();
                unique_ptr<Transportation> transport = createTransportation(transportType);
                string companyName = it->getCompanyName();
                int ticketCount = it->getTicketCount();
                transport->increaseCapacity(companyName, ticketCount);

                bookings.erase(it);
                cout << "Pemesanan berhasil dihapus!\n";
            } else {
                cout << "Penghapusan dibatalkan.\n";
            }

        } else if (choice == 4) {
            // Menampilkan pemesanan yang ada
            if (bookings.empty()) {
                cout << "Belum ada pemesanan yang dilakukan.\n";
            } else {
                for (const auto& booking : bookings) {
                    booking.displayBooking();
                }
            }

        } else if (choice == 5) {
            // Exit
            break;

        } else {
            cout << "Pilihan tidak valid.\n";
        }
    }

    return 0;
}
