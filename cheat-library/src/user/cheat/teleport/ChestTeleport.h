#pragma once
#include "ItemTeleportBase.h"

namespace cheat::feature 
{

	class ChestTeleport : public ItemTeleportBase
    {
	public:

		// Chest state filters
		config::field::BaseField<bool> m_FilterChestLocked;
		config::field::BaseField<bool> m_FilterChestInRock;
		config::field::BaseField<bool> m_FilterChestFrozen;
		config::field::BaseField<bool> m_FilterChestBramble;
		config::field::BaseField<bool> m_FilterChestTrap;

		// Chest rarity filters
		config::field::BaseField<bool> m_FilterChestCommon;
		config::field::BaseField<bool> m_FilterChestExquisite;
		config::field::BaseField<bool> m_FilterChestPrecious;
		config::field::BaseField<bool> m_FilterChestLuxurious;
		config::field::BaseField<bool> m_FilterChestRemarkable;

		// Type filters
		config::field::BaseField<bool> m_FilterChest;
		config::field::BaseField<bool> m_FilterInvestigates;
		config::field::BaseField<bool> m_FilterBookPage;
		config::field::BaseField<bool> m_FilterBGM;

		config::field::BaseField<bool> m_FilterUnknown;

		static ChestTeleport& GetInstance();

		const FeatureGUIInfo& GetGUIInfo() const final;
		virtual void DrawFilterOptions() final;

		enum class FilterStatus
		{
			Unknown,
			Valid,
			Invalid
		};

		enum class ItemType
		{
			None,
			Chest,
			Investigate,
			BookPage,
			BGM
		};

		enum class ChestState
		{
			Invalid,
			None,
			Locked,
			InRock,
			Frozen,
			Bramble,
			Trap
		};

		enum class ChestRarity
		{
			Unknown,
			Common,
			Exquisite,
			Precious,
			Luxurious,
			Remarkable
		};

		FilterStatus FilterChest(app::BaseEntity* entity);

		void DrawItems() final;
		
		bool NeedInfoDraw() const final;
		void DrawInfo() final;

	private:

		void DrawChests();
		void DrawUnknowns();

		ChestTeleport();
	};
}

