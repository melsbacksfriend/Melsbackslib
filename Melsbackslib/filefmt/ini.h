#ifndef INI_H
#define INI_H

#include <string>
#include <fstream>
#include <vector>

namespace melsbackslib
{
	class inifile {
		public:
			std::string getval(const char* inipath, const char* group, const char* var) {
				std::string groupcpp = group;
                std::string inigroup = "[" + groupcpp + "]";
				std::string varcpp = var;
                varcpp = varcpp + "=";
				std::ifstream iniin (inipath);
                std::string tmpstr;
                std::string val;
				std::vector<std::string> inivect;
                while(!iniin.eof())
                {
                    std::getline(iniin, tmpstr, '\n');
                    inivect.push_back(tmpstr);
                }
                iniin.close();
                for (int i = 0; i < inivect.size(); i++)
                {
                    std::size_t found = inivect[i].find(inigroup.c_str());
                    if (found != std::string::npos)
                    {
                        for (int j = i + 1; j < inivect.size(); j++)
                        {
                            std::size_t found2 = inivect[j].find('[');
                            std::size_t found3 = inivect[j].find(';');
                            if (found2 == std::string::npos && found3 == std::string::npos)
                            {
                                std::size_t found4 = inivect[j].find(varcpp.c_str());
                                if (found4 != std::string::npos)
                                {
                                    std::size_t found5 = inivect[j].find('=');
                                    if (found5 != std::string::npos)
                                    {
                                        val = inivect[j].substr(found5 + 1);
                                    }
                                }
                            }
                            if (found2 != std::string::npos)
                            {
                                break;
                            }
                        }
                    }
                }
                return val;
			}
            void setval(const char* inipath, const char* group, const char* var, const char* val)
            {
				std::string groupcpp = group;
                std::string inigroup = "[" + groupcpp + "]";
				std::string varcpp = var;
                varcpp = varcpp + "=";
                std::string valcpp = val;
				std::ifstream iniin (inipath);
                std::string tmpstr;
				std::vector<std::string> inivect;
                while (!iniin.eof())
                {
                    std::getline(iniin, tmpstr, '\n');
                    inivect.push_back(tmpstr);
                }
                iniin.close();
                for (int i = 0; i < inivect.size(); i++)
                {
                    std::size_t found = inivect[i].find(inigroup.c_str());
                    if (found != std::string::npos)
                    {
                        for (int j = i + 1; j < inivect.size(); j++)
                        {
                            std::size_t found2 = inivect[j].find('[');
                            std::size_t found3 = inivect[j].find(';');
                            if (found2 == std::string::npos && found3 == std::string::npos)
                            {
                                std::size_t found4 = inivect[j].find(varcpp.c_str());
                                if (found4 != std::string::npos)
                                {
                                    std::size_t found5 = inivect[j].find('=');
                                    if (found5 != std::string::npos)
                                    {
                                        inivect[j].erase(found5 + 1);
                                        inivect[j].insert(found5 + 1, valcpp.c_str());
                                        std::ofstream iniout(inipath);
                                        for (int k = 0; k < inivect.size(); k++)
                                        {
                                            iniout << inivect[k] << std::endl;
                                        }
                                        iniout.close();
                                    }
                                }
                            }
                            if (found2 != std::string::npos)
                            {
                                break;
                            }
                        }
                    }
                }
			}
            void addgroup(const char* inipath, const char* group)
            {
				std::string groupcpp = group;
                std::string inigroup = "[" + groupcpp + "]";
                std::fstream iniout(inipath, std::ios::app);
                iniout << std::endl << inigroup << std::endl;
                iniout.close();
            }
            void addval(const char* inipath, const char* group, const char* var, const char* val)
            {
				std::string groupcpp = group;
                std::string inigroup = "[" + groupcpp + "]";
				std::string varcpp = var;
                varcpp = varcpp + "=";
                std::string valcpp = val;
				std::ifstream iniin (inipath);
                std::string tmpstr;
				std::vector<std::string> inivect;
                while (!iniin.eof())
                {
                    std::getline(iniin, tmpstr, '\n');
                    inivect.push_back(tmpstr);
                }
                iniin.close();
                for (int i = 0; i < inivect.size(); i++)
                {
                    std::size_t found = inivect[i].find(inigroup.c_str());
                    if (found != std::string::npos)
                    {
                        inivect.emplace(inivect.begin() + i + 1, varcpp + valcpp);
                        std::ofstream iniout(inipath);
                        for (int j = 0; j < inivect.size(); j++)
                        {
                            iniout << inivect[j] << std::endl;
                        }
                    }
                }
            }
	};
}

#endif // INI_H