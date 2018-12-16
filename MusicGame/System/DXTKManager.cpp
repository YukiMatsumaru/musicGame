#include "../pch.h"
#include "DXTKManager.h"

using namespace DirectX;

DXTK::DXTKManager::DXTKManager()
{
	m_keyboard = std::make_unique<Keyboard>();
	m_keyTracker = std::make_unique<Keyboard::KeyboardStateTracker>();
}

void DXTK::DXTKManager::Initializer(ID3D11Device* device, ID3D11DeviceContext* context)
{
	m_device = device;
	m_context = context;

	// �R�����X�e�[�g���쐬
	m_state = std::make_unique<CommonStates>(device);

	// �X�v���C�g�o�b�`
	m_spriteBatch = std::make_unique<SpriteBatch>(context);

	// �X�v���C�g�t�H���g
	m_spriteFont = std::make_unique<SpriteFont>(device, L"myfile.spritefont");
}

void DXTK::DXTKManager::UpdateInputState()
{
	// �L�[���͏����擾
	Keyboard::State key = m_keyboard->GetState();
	m_keyTracker->Update(key);

}