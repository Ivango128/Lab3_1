#include <iostream>
#include <string>

class OutboardMotor {
	std::string brand_;
	int power_;
	std::string tact_;

public:
	// Конструктор без параметров
	OutboardMotor(): brand_("No_name"), power_(0), tact_("zero") {
		std::cout << brand_ << " - конструктор по умолчанию" << std::endl;
	}
	// Конструктор с параметрами
	OutboardMotor(std::string brand, int power, std::string tact): brand_(brand), power_(power), tact_(tact) {
		std::cout << brand_ << " - конструктор c параметрами" << std::endl;
	// Копируюший конструктор
	}
	OutboardMotor(const OutboardMotor& other) : brand_(other.brand_), power_(other.power_), tact_(other.tact_) {
		std::cout << brand_ << " - копирующий конструктор" << std::endl;
	}
	~OutboardMotor() {
		std::cout << brand_ << " деструктор" << std::endl;
	}
	// Функция вывода данных в консоль
	void Show() {
		std::cout << "Бренд " << brand_ << "\n"
			<< "Мощность " << power_ << "\n"
			<<  tact_ << " тактный" << std::endl;
	}
	// Функции для получения данных
	std::string GetBrand() const {
		return brand_;
	}
	int GetPower() const {
		return power_;
	}
	std::string GetTact() const {
		return tact_;
	}
	// Функции для установки данных
	void Set(std::string brand, int power, std::string tact) {
		SetBrand(brand);
		SetPower(power);
		SetTact(tact);
	}
	void SetBrand(std::string brand) {
		brand_ = brand;
	}
	void SetPower(int power) {
		power_ = power;
	}
	void SetTact(std::string tact) {
		tact_ = tact;
	}
	
};

void View(OutboardMotor e) { e.Show(); }
OutboardMotor NoName(OutboardMotor& e) {
	OutboardMotor t(e);
	t.SetBrand("noname");
	return t;
}

int main(){
	setlocale(LC_ALL, "");

	// Создается указатель на функцию
	void (OutboardMotor:: * GetInfo) ();
	
	// указателю на функцию присваивается на функцию Show
	GetInfo = &OutboardMotor::Show;
	
	// Используется конструктор по умолчанию
	OutboardMotor* yamaha = new OutboardMotor{}; 

	// Используется конструктор с параметрами
	OutboardMotor* suzuki = new OutboardMotor("сузуки", 5, "4-ех"); 

	// Вызов функции по указателю на функцию
	(*suzuki.*GetInfo)(); 

	// Вызов функции по указателю на объект
	yamaha->Set("ямаха", 6, "4-ех"); 

	// Вызов деструктора
	delete yamaha;

	// создает новый объект ewew класса OutboardMotor, который инициализируется данными из объекта *suzuki  (копирующий конструктор используется по умолчанию)
	OutboardMotor ewew = *suzuki; 

	// вызывает функцию View, которая выводит информацию о переданном объекте
	View(ewew); 

	//(копирующий конструктор используется явно)
	OutboardMotor prog(*suzuki); 

	//создает массив Motors из трех объектов Exam, инициализирующихся с помощью различных конструкторов
	OutboardMotor Motors[3] = {
		*suzuki, NoName(*suzuki), OutboardMotor("сузуки", 5, "4-ех")
	};

	// выделяет динамический массив из трех объектов
	OutboardMotor* p = new OutboardMotor[3]; 

	// устанавливает данные второго элемента массива p с помощью метода Set.
	(p + 1)->Set("митсубиши", 20, "6-ти"); 

	//  создает новый объект pp класса OutboardMotor, который инициализируется данными из второго элемента массива p
	auto pp = *(p + 1); 

	// Вызов функции по указателю на функцию
	(*suzuki.*GetInfo)();

	// создает указатель suzukiptr на объект suzuki и вызывает метод Show через указатель suzukiptr
	OutboardMotor* suzukiptr = suzuki;
	suzukiptr->Show();

	return 0;
}