#pragma once

namespace Scene
{
	class SceneManager;

	class Scene
	{
	public:
		virtual ~Scene() = default;

		virtual void Update(SceneManager& manager) = 0;
		virtual void Draw() = 0;
	
		static bool prevScene;
	};
}