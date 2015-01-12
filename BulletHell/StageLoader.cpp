#include "StageLoader.h"

void StageLoader::loadEnemiesFromStage(string fileName, vector<Enemy*>& enemyVector){

	string line;
	ifstream stageFile(fileName);
	vector<int> subLines;

	int typeCode;
	int x;
	int y;
	int vX;
	int vY;
	int t;

	if(stageFile.is_open()){

		//stringstream ss(line);
		string item;
		int infoNumber;

		while(stageFile >> typeCode >> x >> y >> vX >> vY >> t){
			
			stringstream(typeCode) >> typeCode;
			stringstream(x) >> x;
			stringstream(y) >> y;
			stringstream(vX) >>vX;
			stringstream(vY) >> vY;
			stringstream(t) >> t;

			switch(typeCode){
			
			case SpiralEnemyCode:
				//SpiralEnemy(subLines[1],subLines[2],subLines[3],subLines[4],subLines[5]);
				enemyVector.push_back(new SpiralEnemy(x,y,vX,vY,t));
				break;
			case SpreadEnemyCode:
				enemyVector.push_back(new SpreadEnemy(x,y,vX,vY,t));
				break;
			default:
				cout << "Error in stagefileCode";
				break;
			}
		
		}
			

		stageFile.close();


	}else{
		cout << "Error opening file " + fileName;
	}

}