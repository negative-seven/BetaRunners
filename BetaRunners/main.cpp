#include <conio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::string p_username, p_app, p_depot, p_manifest, p_version;
	std::vector<std::vector<std::string>> manifestpairs;

	std::ios_base::sync_with_stdio(false);

	std::ifstream file("versions.txt");
	std::string buffer;
	while (std::getline(file, buffer))
	{
		if (buffer[0] == '#') continue; // Ignore lines that start with '#'
		manifestpairs.push_back({buffer.substr(0, 5) /*Version*/, buffer.substr(6) /*Manifest*/});
	}

	p_app = "207140"; // App: SpeedRunners
	p_depot = "207141"; // Depot: SpeedRunners All Windows Files

	std::cout << "Username: ";
	std::cin >> p_username;

	std::string input;
	unsigned int num;
	std::cout << "Manifest no. [1-" + std::to_string(manifestpairs.size()) + "], version no. [rXX]/[rXX.XX] or manifest id [mXXX...]: ";
	std::cin >> input;

	if (input[0] == 'r' || input[0] == 'R')
	{
		for (auto &manifestpair : manifestpairs)
		{
			if (manifestpair[0] == input.substr(1) || manifestpair[0].substr(0, 2) == input.substr(1))
			{
				p_manifest = manifestpair[1];
				p_version = manifestpair[0];
			}
		}

		if (p_manifest.empty()) {
			std::cout << "Could not find version r" << input.substr(1) << "\n";
			_getch();
			return 1;
		}
	}
	else if (input[0] == 'm' || input[0] == 'M')
	{
		for (auto &manifestpair : manifestpairs)
		{
			if (manifestpair[1] == input.substr(1))
			{
				p_manifest = manifestpair[1];
				p_version = manifestpair[0];
			}
		}

		if (p_manifest.empty()) {
			std::cout << "Could not find manifest id " << input.substr(1) << "\n";
			_getch();
			return 1;
		}
	}
	else
	{
		num = atoi(input.c_str());
		if (num > manifestpairs.size() || num == 0)
		{
			std::cout << "Invalid manifest number " << input << "\n";
			_getch();
			return 1;
		}
		p_manifest = manifestpairs[num-1][1];
		p_version = manifestpairs[num-1][0];
	}

	std::string cmd = "DepotDownloader.exe -username " + p_username + " -app " + p_app + " -depot " + p_depot + " -manifest "
					+ p_manifest + " -dir \"SpeedRunners\\r" + (p_version == "??.??" ? "##.##" : p_version) + " (" + p_manifest + ")\"";
	std::cout << "Launching DepotDownloader with command: \"" + cmd + "\"\n\n";
	system(cmd.c_str());
	_getch();

	return 0;
}