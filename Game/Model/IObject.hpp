#pragma once

namespace g8
{
	class IStageObject
	{
	public:

		//最初のフレームの開始前に一度だけ呼ばれる
		//いらないかも
		virtual void Start() {};

		//当たり判定の前に呼ばれる
		virtual void Update1() {};
		//当たり判定の後に呼ばれる
		virtual void Update2() {};
	};
}