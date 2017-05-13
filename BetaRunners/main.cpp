#include <conio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string p_username, p_password, p_app, p_depot, p_manifest;
	std::vector<std::string> manifests;

	std::ios_base::sync_with_stdio(false);

	std::ifstream file("manifests.txt");
	std::string buffer;
	while (std::getline(file, buffer))
	{
		manifests.push_back(buffer);
	}

	p_app = "207140"; // App: SpeedRunners
	p_depot = "207141"; // Depot: SpeedRunners All Windows Files

	std::cout << "Username: ";
	std::cin >> p_username;

	std::cout << "Password: ";
	std::cin >> p_password;

	unsigned int temp;
	std::cout << "Manifest no. [0-" + std::to_string(manifests.size() - 1) + "]: ";
	std::cin >> temp;
	if (temp > manifests.size() - 1)
	{
		std::cout << "Invalid manifest no.\n";
		_getch();
		return 1;
	}
	p_manifest = manifests[temp];

	std::string cmd = "DepotDownloader.exe -username " + p_username + " -password " + p_password + " -app " + p_app + " -depot " + p_depot + " -manifest " + p_manifest;
	std::cout << "Launching DepotDownloader with command: \"" + cmd + "\"\n\n";
	system(cmd.c_str());
	_getch();

	return 0;
}