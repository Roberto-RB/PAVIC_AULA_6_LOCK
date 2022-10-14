#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
#include <atomic>

//unsigned namespece std;
//unsigned int contador = 0;

std::atomic <unsigned int> contador(0);

std::mutex chave;



void fun_thread() {

	//chave.lock();
	for (int i = 0; i < 5; i++) {
		printf(" Esperar thread: %d :  i: %d...\n", std::this_thread::get_id(), i);
		//cout << " Esperar thread:" << std::this_thread::get_id() << std::endl;

		// Timer sleep 500 milliseconds
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		//chave.lock();
		contador++;
		//chave.unlock();
	}
	//chave.unlock();

}

int main() {

	std::thread thread01(fun_thread);
	std::thread thread02(fun_thread);

	thread01.join();
	thread02.join();

	printf("Contador %d", contador.load());  	// Atomic contador.load()
	//std::cout << " Contador " << contador << std::endl;

}