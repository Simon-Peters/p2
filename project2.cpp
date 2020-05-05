
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>

using namespace std;

int room1 = 0;
int room2 = 7;
using namespace std;
//GLOBAL VARIABLES
string choice;
string crowbarstring = "Weapon: Crowbar\n";
string knifestring = "Weapon: Knife\n";
string lobstertrapstring = "Weapon: Lobstertrap\n";
string voldebortstring = "Weapon: Voldebort\n";
string shortswordstring = "Weapon: Shortsword\n";
string longswordstring = "Weapon: Longsword\n";
string blunderbussstring = "Weapon: Blunderbuss\n";
string boomstickstring = "Weapon: Boomstick\n";
string tacticalnukestring = "Weapon: Tactical Nuke\n";
string fistsstring = "Weapon: Fists\n";
int lobsterscare = 0;
int bortscare = 0;
int gold = 0;
int attack = 5;
int hpotionnum = 10;
int spotionnum = 5;
int hpotionshopnum = 10; int spotionshopnum = 10; int crowbarnum = 1; int knifenum = 1; int lobstertrapnum = 1; int shortswordnum = 1; int longswordnum = 1;
int boomsticknum = 1; int blunderbussnum = 1; int tacticalnukenum = 1; int voldebortnum = 1;
int dowhvar = 10;
//ITER AND VECTOR
vector <string> backpack;
vector <string>::const_iterator iter;

class lobster
{
public:
	int l_position = 2;
	int l_attack = 10;
	int l_health = 30;
	int l_goldgiven = 20;
	int l_turn = 0;
};

class bort
{
public:
	int b_attack = 10;
	int b_health = 50;
	int b_position = 2;
	int b_goldgiven = 50;
	int b_turn = 0;
};

class gerald
{
public:
	int g_attack = 10;
	int g_health = 50;
	int g_position = 2;
	int g_goldgiven = 711;
	int g_turn = 0;
};

int enemyattack(int attack, int playerhealth);

int playerbattle(int playerattack, int enemyhealth, string choice);

void shoplist();

void shopbuy();

void shoppyboi();


int main()
{
	srand(time(NULL));
	int playerhealth = 100;

	bool holdarea = true;
	bool dungeon1 = false;
	bool dungeon2 = false;
	bool dungeon3 = false;
	bool shop = false;
	bool tutorial = false;
	int dungeonwin = 0;
	bool weaponcheck = false;
	int port = 1;
	bool allwin = false;

	bool inbattle = false;
	int enemies = 0;
	int const standlobhealth = 30;
	int const standborthealth = 50;
	int const standgeraldhealth = 100;
	int gold = 0;
	int playerstrength = 0;
	backpack.push_back(shortswordstring);
	do
	{
		switch (port)
		{
		case 1:
			do
			{
				cout << "You are in a large, spacious area.\nThere are three doorways.\nThere is also a small blue market stall off to the right.";
				if (weaponcheck == true)
				{
					cout << "What would you like to do?\n(a = go to door one/b = go to door two/c = go to door three/d go to tutorial/e go to shop)\n";
					cout << "Your health has been fully restored.\n";
					cin >> choice;
					if (choice == "a")
					{
						port = 4;
						dungeon1 = true;
						holdarea = false;
						break;
					}
					else if (choice == "b")
					{
						port = 5;
						dungeon2 = true;
						holdarea = false;
						break;
					}
					else if (choice == "c")
					{
						port = 6;
						dungeon3 = true;
						holdarea = false;
						break;
					}
					else if (choice == "d")
					{
						port = 3;
						tutorial = true;
						holdarea = false;
						break;

					}
					else if (choice == "e")
					{
						port = 2;
						shop = true;
						holdarea = false;
						break;
					}
				}
				else
				{
					do
					{
						cout << "You hear a yell from the market shop. 'Adventurer, surely you need a weapon before venturing into the dungeon!'\n";
						cout << "He continues, 'As I do not want to see another person massacred today, I will give you a weapon for free.'\n";
						cout << "You approach him cautiously as he presents a weapon to you. He gives you a small sword.\n";
						cout << "'I know it's not much, but if I gave free things to everyone I'd be out of business.' He chuckles.\n";
						cout << "'So you see those doors over there? The higher the door number goes, the harder it gets.'\n";
						cout << "'Room one is probably the best bet for your survival, adventurer. Good choice!\nHe looks at the door for room one.\n";
						cout << "Oh! If you don't know how to fight, by the way, just ask for the tutorial (type tutorial into the console).\nAnyways, try not to die!'\n\n";
						playerstrength = 5;
						weaponcheck = true;

					} while (weaponcheck == false);
				}

			} while (holdarea == true);

		case 2:
			if (shop == true)
			{
				do
				{
					cout << "\nYou enter the shop.\nDo you want to shop here?\n" << "Type y to shop, type n to leave.\n";
					cin >> choice;
					if (choice == "y")
					{
						shoplist();
						cin >> choice;
						if (choice == "y")
						{
							shopbuy();
						}
						if (choice == "n")
						{
							cout << " You decided to return to the game instead of shopping.";
							port = 1;
							holdarea = true;
							shop = false;
							break;
						}
					}
					if (choice == "n")
					{
						cout << "You chose not to enter the shop.";
						port = 1;
						holdarea = true;
						shop = false;
						break;
					}
					break;
				} while (shop == true);

			}
		case 3:
			if (tutorial == true)
			{
				cout << "You ask the shopkeeper if you can do the tutorial.\n";
				cout << "'Why, of course,' he says, 'just follow me.'\nHe leads you to an area behind the shop. A single training dummy stares as you with cold eyes.\n";
				cout << "'First off, you interact with an enemy by typing fight.'\n";
				cout << "'Next, if you want to do damage to the enemy, type attack.'\n";
				cout << "'If you want to see your items in your inventory, type item.\n";
				cout << "'If you want to run from the fight, type run.'\n";
				cout << "'If you want to exit the dungeon, type exit.'\n\n";
				holdarea = true;
				port = 1;
				tutorial = false;
				break;

			}

		case 4:
			do
			{
				enemies = rand() % 5 + dungeonwin;
				enemies = enemies + 1;
				while (playerhealth > 0 && enemies > 0 && dungeon1 == true)
				{
					cout << "There are " << enemies << " enemies.\n";
					cout << "What would you like to do?\n";
					cin >> choice;
					if (choice == "fight" && enemies > 0)
					{
						inbattle = true;
						lobster lobster1;
						lobster1.l_health = 40;
						do
						{
							if (lobster1.l_health > 0 && inbattle == true)
							{
								cout << "You are in battle. What would you like to do?\n";
								cin >> choice;

								if (choice == "attack")
								{
									playerhealth = enemyattack(lobster1.l_attack, playerhealth);
									lobster1.l_health = playerbattle(playerstrength, lobster1.l_health, choice);

								}
								else if (choice == "item")
								{
									for (int i = 0; i < backpack.size(); i++)
										cout << backpack.at(i) << ' ';
								}
								else if (choice == "run")
								{
									cout << "You ran away.\n";
									lobster1.l_health = standlobhealth;
									inbattle = false;
								}
								else
								{
									cout << "That is not an accepted command.\n";
								}
							}
							else if (lobster1.l_health <= 0)
							{
								inbattle = false;
								cout << "The enemy has died.\n";
								gold = gold + lobster1.l_goldgiven;
								cout << "You have " << gold << " gold.\n";
								enemies = enemies - 1;
							}

						} while (enemies > 0 && playerhealth > 0 && inbattle == true);
					}
					else if (choice == "exit")
					{
						cout << "You have chosen to exit the dungeon.\n";
						port = 1;
						holdarea = true;
						dungeon1 = false;
						break;
					}
					else if (choice == "item")
					{
						for (int i = 0; i < backpack.size(); i++)
							cout << backpack.at(i) << ' ';
					}
					else
					{
						cout << "Please type an accepted command.";
					}
				}
				if (playerhealth <= 0)
				{
					cout << "You have died.\n";
					return 0;
				}
				if (enemies <= 0 && dungeon1 == true)
					cout << "You have beaten the dungeon! You get 100 gold.\n";
				dungeonwin = dungeonwin + 2;
				gold = gold + 100;
				while (dungeon1 == true)
				{
					cout << "There are no enemies in the dungeon.(exit the dungeon and come back if you would like to fight more)\n";
					cin >> choice;
					if (choice == "exit")
					{
						port = 1;
						holdarea = true;
						dungeon1 = false;
						break;
					}

				}

			} while (dungeon1 == true);
			break;

		case 5:
			do
			{

				{
					enemies = rand() % 3 + dungeonwin;
					enemies = enemies + 1;
					while (playerhealth > 0 && enemies > 0 && dungeon1 == true)
					{
						cout << "There are " << enemies << " enemies.\n";
						cout << "What would you like to do?\n";
						cin >> choice;
						if (choice == "fight" && enemies > 0)
						{
							inbattle = true;
							bort bort1;
							bort1.b_health = standborthealth;
							do
							{
								if (bort1.b_health > 0 && inbattle == true)
								{
									cout << "You are in battle. What would you like to do?\n";
									cin >> choice;

									if (choice == "attack")
									{
										playerhealth = enemyattack(bort1.b_attack, playerhealth);
										bort1.b_health = playerbattle(playerstrength, bort1.b_health, choice);

									}
									else if (choice == "item")
									{
										for (int i = 0; i < backpack.size(); i++)
											cout << backpack.at(i) << ' ';
									}
									else if (choice == "run")
									{
										cout << "You ran away.\n";
										bort1.b_health = standborthealth;
										inbattle = false;
									}
									else
									{
										cout << "That is not an accepted command.\n";
									}
								}
								else if (bort1.b_health <= 0)
								{
									inbattle = false;
									cout << "The enemy has died.\n";
									gold = gold + bort1.b_goldgiven;
									cout << "You have " << gold << " gold.\n";
									enemies = enemies - 1;
								}

							} while (enemies > 0 && playerhealth > 0 && inbattle == true);
						}
						else if (choice == "exit")
						{
							cout << "You have chosen to exit the dungeon.\n";
							port = 1;
							holdarea = true;
							dungeon1 = false;
							break;
						}
						else if (choice == "item")
						{
							for (int i = 0; i < backpack.size(); i++)
								cout << backpack.at(i) << ' ';
						}
						else
						{
							cout << "Please type an accepted command.";
						}
					}
					if (playerhealth <= 0)
					{
						cout << "You have died.\n";
						return 0;
					}
					if (enemies <= 0 && dungeon2 == true)
						cout << "You have beaten the dungeon! You get 100 gold.\n";
					dungeonwin = dungeonwin + 2;
					gold = gold + 200;
					while (dungeon2 == true)
					{
						cout << "There are no enemies in the dungeon.(exit the dungeon and come back if you would like to fight more)\n";
						cin >> choice;
						if (choice == "exit")
						{
							port = 1;
							holdarea = true;
							dungeon2 = false;
							break;
						}

					}

				}

			} while (dungeon2 == true);
			break;

		case 6:
			do
			{
				enemies = 1;
				while (playerhealth > 0 && enemies > 0 && dungeon3 == true)
				{
					cout << "There are " << enemies << " enemies.\n";
					cout << "What would you like to do?\n";
					cin >> choice;
					if (choice == "fight" && enemies > 0)
					{
						inbattle = true;
						gerald gerald1;
						gerald1.g_health = standgeraldhealth;
						do
						{
							if (gerald1.g_health > 0 && inbattle == true)
							{
								cout << "You are in battle. What would you like to do?\n";
								cin >> choice;

								if (choice == "attack")
								{
									playerhealth = enemyattack(gerald1.g_attack, playerhealth);
									gerald1.g_health = playerbattle(playerstrength, gerald1.g_health, choice);

								}
								else if (choice == "item")
								{
									for (int i = 0; i < backpack.size(); i++)
										cout << backpack.at(i) << ' ';
								}
								else if (choice == "run")
								{
									cout << "You ran away.\n";
									gerald1.g_health = standlobhealth;
									inbattle = false;
								}
								else
								{
									cout << "That is not an accepted command.\n";
								}
							}
							else if (gerald1.g_health <= 0)
							{
								inbattle = false;
								cout << "The enemy has died.\n";
								gold = gold + gerald1.g_goldgiven;
								cout << "You have " << gold << " gold.\n";
								enemies = enemies - 1;
							}

						} while (enemies > 0 && playerhealth > 0 && inbattle == true);
					}
					else if (choice == "exit")
					{
						cout << "You have chosen to exit the dungeon.\n";
						port = 1;
						holdarea = true;
						dungeon3 = false;
						break;
					}
					else if (choice == "item")
					{
						for (int i = 0; i < backpack.size(); i++)
							cout << backpack.at(i) << ' ';
					}
					else
					{
						cout << "Please type an accepted command.";
					}
				}
				if (playerhealth <= 0)
				{
					cout << "You have died.\n";
					return 0;
				}
				if (enemies <= 0 && dungeon3 == true)
					cout << "You have beaten the dungeon! You get 100 gold.\n";
				dungeonwin = dungeonwin + 2;
				gold = gold + 300;
				while (dungeon3 == true)
				{
					cout << "There are no enemies in the dungeon.(exit the dungeon and come back if you would like to fight more)\n";
					cin >> choice;
					if (choice == "exit")
					{
						port = 1;
						holdarea = true;
						dungeon3 = false;
						break;
					}

				}

			} while (dungeon3 == true);
			break;


		}

	} while (allwin == false);
}

int enemyattack(int attack, int playerhealth)
{
	playerhealth = playerhealth - attack;
	cout << "The enemy attacks you for " << attack << " health.\n";
	cout << "You have " << playerhealth << " health left.\n";
	return playerhealth;

}

int playerbattle(int playerattack, int enemyhealth, string choice)
{
	if (choice == "attack")
	{
		enemyhealth = enemyhealth - attack;
		cout << "You attack the enemy for " << attack << " health.\n";
		cout << "The enemy has " << enemyhealth << " health left.\n";
	}
	return enemyhealth;
}

void shoplist()
{
	cout << "\nAwesome, here's a list of the items we have for purchase.\n";
	if (hpotionshopnum > 0)
	{
		cout << "\nWe have " << hpotionshopnum << " healthpotion. - healthpotion";
	}
	if (spotionshopnum > 0)
	{
		cout << "\nWe have " << spotionshopnum << " strengthpotion. - strengthpotion";
	}
	if (crowbarnum > 0)
	{
		cout << "\nWe have " << crowbarnum << " crowbar. - crowbar";
	}
	if (knifenum > 0)
	{
		cout << "\nWe have " << knifenum << " knife. - knife\n";
	}
	if (lobstertrapnum > 0)
	{
		cout << "We have " << lobstertrapnum << " lobstertrap. - lobstertrap\n";
	}
	if (voldebortnum > 0)
	{
		cout << "We have " << voldebortnum << " voldebort. - voldebort\n";
	}
	if (shortswordnum > 0)
	{
		cout << "We have " << shortswordnum << " shortsword. - shortsword\n";
	}
	if (longswordnum > 0)
	{
		cout << "We have " << longswordnum << " longsword. - longsword\n";
	}
	if (blunderbussnum > 0)
	{
		cout << "We have " << blunderbussnum << " blunderbuss. - blunderbuss\n";
	}
	if (boomsticknum > 0)
	{
		cout << "We have " << boomsticknum << " boomstick. - boomstick\n";
	}
	if (tacticalnukenum > 0)
	{
		cout << "We have " << tacticalnukenum << " tacticalnuke. - tacticalnuke\n";
	}
	cout << "\n\nIf you would like to purchase any of these, type y. If you would like to leave, type n.\n";
}

void shopbuy()
{
	cout << "\nIf you want to buy any of these items, type their names, and if you have enough gold, you'll be able to purchase them.\nNames are listed after the - on the list.\n\n";
	cin >> choice;
	if (choice == "healthpotion" && gold >= 10 && hpotionshopnum > 0)
	{
		cout << "This will cost 10 gold to purchase, are you sure you want to buy it?\nType y if you want to purchase it, type n if you want to leave.\n";
		cin >> choice;
		if (choice == "y")
		{
			gold = gold - 10;
			hpotionnum = hpotionnum + 1;
			hpotionshopnum = hpotionshopnum - 1;
			cout << "\nYou now have " << hpotionnum << " healthpotions.\n";
			shoppyboi();

		}
		if (choice == "n")
		{
			cout << "You decide to stop looking at the item.";
			shoppyboi();
		}
	}
	if (choice == "strengthpotion" && gold >= 10 && spotionshopnum > 0)
	{
		cout << "This will cost 10 gold to purchase, are you sure you want to buy it?\nType y if you want to purchase it, type n if you want to leave.\n";
		cin >> choice;
		if (choice == "y")
		{
			gold = gold - 10;
			spotionnum = spotionnum + 1;
			spotionshopnum = spotionshopnum - 1;
			cout << "\nYou now have " << spotionnum << " strengthpotions.\n";
			shoppyboi();

		}
		if (choice == "n")
		{
			cout << "You decide to stop looking at the item.";
			shoppyboi();
		}
	}
	if (choice == "crowbar" && gold >= 50 && crowbarnum > 0)
	{
		cout << "\nThe crowbar isn't much of an upgrade, but at least it's something.\n" << "This will cost 50 gold to purchase, are you sure you want to buy it?\nType y if you want to purchase it, type n if you want to leave.\n";
		cin >> choice;
		if (choice == "y")
		{
			gold = gold - 50;
			iter = find(backpack.begin(), backpack.end(), fistsstring);
			if (iter != backpack.end())
			{
				*iter == crowbarstring;
			}
			backpack.push_back(crowbarstring);
			cout << "Crowbar has been added to your inventory.";
			crowbarnum = crowbarnum - 1;
			attack = 15;
			bortscare = 0;
			lobsterscare = 0;
			shoppyboi();

		}
		if (choice == "n")
		{
			cout << "You decide to stop looking at the item.";
			shoppyboi();
		}
	}
	if (choice == "knife" && gold >= 75 && knifenum > 0)
	{
		cout << "\nYou suspect that the knife is dull, but it looks pretty long and the metal shines from underneath the rust.\n" << "This will cost 75 gold to purchase, are you sure you want to buy it?\nType y if you want to purchase it, type n if you want to leave.\n";
		cin >> choice;
		if (choice == "y")
		{
			gold = gold - 75;
			iter = find(backpack.begin(), backpack.end(), crowbarstring);
			if (iter != backpack.end())
			{
				*iter == knifestring;
			}
			backpack.push_back(knifestring);
			cout << "Knife has been added to your inventory.";
			knifenum = knifenum - 1;
			attack = 20;
			lobsterscare = 0;
			bortscare = 0;
			shoppyboi();

		}
		if (choice == "n")
		{
			cout << "You decide to stop looking at the item.";
			shoppyboi();
		}
	}
	if (choice == "lobstertrap" && gold >= 125 && lobstertrapnum > 0)
	{
		cout << "\nAll lobsters fear the lobstertrap, they'll run away, leaving everything behind if they see it.\nUnfortunately, it does minimal damage to everything else.\n" << "This will cost 125 gold to purchase, are you sure you want to buy it?\nType y if you want to purchase it, type n if you want to leave.\n";
		cin >> choice;
		if (choice == "y")
		{
			gold = gold - 125;
			iter = find(backpack.begin(), backpack.end(), knifestring);
			if (iter != backpack.end())
			{
				*iter == lobstertrapstring;
			}
			backpack.push_back(lobstertrapstring);
			cout << "Lobstertrap has been added to your inventory.";
			lobstertrapnum = lobstertrapnum - 1;
			attack = 5;
			lobsterscare = 1;
			bortscare = 0;
			shoppyboi();

		}
		if (choice == "n")
		{
			cout << "You decide to stop looking at the item.";
			shoppyboi();
		}
	}
	if (choice == "voldebort" && gold >= 175 && voldebortnum > 0)
	{
		cout << "\nThe Voldebort is a magical wand that absolutely hates borts. All borts you fight will be instantly vaporized.\nUnfortunately, it's not very effective against other monsters.\nUnfortunately, it does minimal damage to everything else.\n" << "This will cost 175 gold to purchase, are you sure you want to buy it?\nType y if you want to purchase it, type n if you want to leave.\n";
		cin >> choice;
		if (choice == "y")
		{
			gold = gold - 175;
			iter = find(backpack.begin(), backpack.end(), lobstertrapstring);
			if (iter != backpack.end())
			{
				*iter == voldebortstring;
			}
			backpack.push_back(voldebortstring);
			cout << "Voldebort has been added to your inventory.";
			voldebortnum = voldebortnum - 1;
			attack = 10;
			lobsterscare = 0;
			bortscare = 1;
			shoppyboi();

		}
		if (choice == "n")
		{
			cout << "You decide to stop looking at the item.";
			shoppyboi();
		}
	}
	if (choice == "shortsword" && gold >= 200 && shortswordnum > 0)
	{
		cout << "\nThe shortsword is clearly a good weapon, the hilt is gilded, and the blade appears to be made of silver.\n" << "This will cost 200 gold to purchase, are you sure you want to buy it?\nType y if you want to purchase it, type n if you want to leave.\n";
		cin >> choice;
		if (choice == "y")
		{
			gold = gold - 200;
			iter = find(backpack.begin(), backpack.end(), voldebortstring);
			if (iter != backpack.end())
			{
				*iter == shortswordstring;
			}
			backpack.push_back(shortswordstring);
			cout << "Shortsword has been added to your inventory.";
			shortswordnum = shortswordnum - 1;
			attack = 25;
			lobsterscare = 0;
			bortscare = 0;
			shoppyboi();

		}
		if (choice == "n")
		{
			cout << "You decide to stop looking at the item.";
			shoppyboi();
		}
	}
	if (choice == "longsword" && gold >= 300 && longswordnum > 0)
	{
		cout << "\nThe longsword looks like the shortsword. But longer.\n" << "This will cost 300 gold to purchase, are you sure you want to buy it?\nType y if you want to purchase it, type n if you want to leave.\n";
		cin >> choice;
		if (choice == "y")
		{
			gold = gold - 300;
			iter = find(backpack.begin(), backpack.end(), shortswordstring);
			if (iter != backpack.end())
			{
				*iter == longswordstring;
			}
			backpack.push_back(shortswordstring);
			cout << "Longsword has been added to your inventory.";
			longswordnum = longswordnum - 1;
			attack = 30;
			lobsterscare = 0;
			bortscare = 0;
			shoppyboi();

		}
		if (choice == "n")
		{
			cout << "You decide to stop looking at the item.";
			shoppyboi();
		}
	}
	if (choice == "blunderbuss" && gold >= 500 && blunderbussnum > 0)
	{
		cout << "\nThe blunderbuss is the weapon of choice for pirates. It looks like a pistol that someone attached a trumpet to.\nThis causes it to function somewhat similarly to a shotgun.\n" << "This will cost 500 gold to purchase, are you sure you want to buy it?\nType y if you want to purchase it, type n if you want to leave.\n";
		cin >> choice;
		if (choice == "y")
		{
			gold = gold - 500;
			iter = find(backpack.begin(), backpack.end(), longswordstring);
			if (iter != backpack.end())
			{
				*iter == blunderbussstring;
			}
			backpack.push_back(blunderbussstring);
			cout << "Blunderbuss has been added to your inventory.";
			blunderbussnum = blunderbussnum - 1;
			attack = 40;
			lobsterscare = 0;
			bortscare = 0;
			shoppyboi();

		}
		if (choice == "n")
		{
			cout << "You decide to stop looking at the item.";
			shoppyboi();
		}
	}
	if (choice == "boomstick" && gold >= 750 && boomsticknum > 0)
	{
		cout << "\nThe boomstick is, well, the boomstick. Anything that gets near it will be boomed.\n" << "This will cost 750 gold to purchase, are you sure you want to buy it?\nType y if you want to purchase it, type n if you want to leave.\n";
		cin >> choice;
		if (choice == "y")
		{
			gold = gold - 750;
			iter = find(backpack.begin(), backpack.end(), blunderbussstring);
			if (iter != backpack.end())
			{
				*iter == boomstickstring;
			}
			backpack.push_back(boomstickstring);
			cout << "Boomstick has been added to your inventory.";
			boomsticknum = boomsticknum - 1;
			attack = 60;
			lobsterscare = 0;
			bortscare = 0;
			shoppyboi();

		}
		if (choice == "n")
		{
			cout << "You decide to stop looking at the item.";
			shoppyboi();
		}
	}
	if (choice == "tacticalnuke" && gold >= 2500 && tacticalnukenum > 0)
	{
		cout << "\nThe tactical nuke is a modern day version of the holy hand grenade. You throw it, and anything within blast radius will be eliminated.\nThis is literally the highest amount of gold you can get in the game, so if you saved up and bought it, you da real MVP.\n" << "This will cost 2500 gold to purchase, are you sure you want to buy it?\nType y if you want to purchase it, type n if you want to leave.\n";
		cin >> choice;
		if (choice == "y")
		{
			gold = gold - 750;
			iter = find(backpack.begin(), backpack.end(), boomstickstring);
			if (iter != backpack.end())
			{
				*iter == tacticalnukestring;
			}
			backpack.push_back(tacticalnukestring);
			cout << "Tactical Nuke has been added to your inventory.";
			tacticalnukenum = tacticalnukenum - 1;
			attack = 2500;
			lobsterscare = 0;
			bortscare = 0;
			shoppyboi();

		}
		if (choice == "n")
		{
			cout << "You decide to stop looking at the item.";
			shoppyboi();
		}
	}
}

void shoppyboi()
{
	//SHOP INTEGERS

	cout << "\nYou enter the shop.\nDo you want to shop here?\n" << "Type y to shop, type n to leave.\n";
	cin >> choice;
	if (choice == "y")
	{
		shoplist();
		cin >> choice;
		if (choice == "y")
		{
			shopbuy();
		}
		if (choice == "n")
		{
			cout << " You decided to return to the game instead of shopping.";
		}
	}
	if (choice == "n")
	{
		cout << "You chose not to enter the shop.";
	}
}
