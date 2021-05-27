#include <DxLib.h>

constexpr int scrX = 640;
constexpr int scrY = 480;

//--------------------------------------------------------------------------
//���V�X�e���̏�����
//--------------------------------------------------------------------------
bool SysInit(void)
{
	SetGraphMode(scrX, scrY, 32);
	ChangeWindowMode(true);
	SetWindowText("2016004_��{����");

	if (DxLib_Init() == -1)
	{
		return false;
	}
	return true;
}

//--------------------------------------------------------------------------
//���G���g���|�C���g
//--------------------------------------------------------------------------
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	if (!SysInit())
	{
		return -1;
	}

	while (CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		if (ProcessMessage() != 0)
		{
			// [�~�{�^��]���������Ƃ��ɉ����A�N�V������ݒ�ł���
			break;
		}
		SetDrawScreen(DX_SCREEN_BACK);
		ClsDrawScreen();

		DrawString(scrX / 3, scrY / 2, "Hello C World!", 0xffffff);

		ScreenFlip();
	}
	DxLib_End();
	return 0;
}
