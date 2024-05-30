#include "Player.h"
#include "Enemy.h"
#include "collision.h"
#include "stdio.h"
#include "math.h"


/// <summary>
/// コンストラクタ
/// </summary>
Collision::Collision()
{

}


/// <summary>
/// デストラクタ
/// </summary>
Collision::~Collision()
{

}




void Collision::HitPlayerToEnemy(Player& player, Enemy& enemy)
{
	// 当たったか、当たっていないか
	bool isHit = false;

	VECTOR _playerPos = player.GetPos();
	VECTOR _enemyPos = enemy.GetPos();
	double _rPlayer = 8;
	double _rEnemy = 8;

	// プレイヤーとエネミーの当たり判定
	// エネミーが存在しているかの値だけもらう
	if (enemy.GetVisibleFlag() == true)
	{
		// プレイヤーからエネミーのベクトル
		VECTOR _difference = VSub(_playerPos, _enemyPos);

		// 絶対値計算
		double distance = sqrt((_difference.x * _difference.x) + (_difference.y * _difference.y) + (_difference.z * _difference.z));

		// 距離を算出
		//double _d = sqrt((_playerPos.x * _enemyPos.x) + (_playerPos.y * _enemyPos.y) + (_playerPos.z * _enemyPos.z));
		// 当たる距離
		double _rSum = _rPlayer + _rEnemy;

		
		// 中心点との距離を求める
		double _PlayerToEnemy = sqrt(pow(_playerPos.x + _enemyPos.x, 2) + pow(_playerPos.y + _enemyPos.y, 2) + pow(_playerPos.z + _enemyPos.z, 2));


		// 半径との距離が2つの半径の合計よりも小さければ
		if ( distance <= _rSum)
		{
			isHit = true;
		}
	}
	// 当たっているか否か
	player.SetIsHitEnemy(isHit);
}

