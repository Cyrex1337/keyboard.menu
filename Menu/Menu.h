#pragma once

#include "KeyHandler.h"
#include <vector>
#include <string>
#include <cstdint>
#include <memory>

extern int testfunc;

namespace Menu
{
	class CItem
	{
	private:
		std::string Description;
		bool Active;
		std::size_t Index;

	public:
		int* Function;
		CItem( ) = default;
		CItem( const std::string& description, bool active = false ) { Description = description; Active = active; }

		std::string GetDescription( ) const { return Description; }
		bool GetActive( ) const { return Active; }
		std::size_t GetIndex( ) const { return Index; }

		void SetActive( bool active ) { Active = active; *Function = active; }
		void SetIndex( std::size_t index ) { Index = index; }
	};

	class CMenu
	{
	private:
		std::string Title;
		std::vector<CItem*> Items;
		std::size_t nCurrent = 0;
		std::size_t nItem = 0;

	public:
		CMenu( ) = default;
		CMenu( const std::string& title );
		~CMenu( );

		std::string GetTitle( ) const { return Title; }
		void GetItems( std::vector<CItem*>& vecItems ) { vecItems = Items; }
		std::size_t GetCurrent( ) const { return nCurrent; }

		void HandleInput( );

		bool GetItemActive( const std::string& description );
		CItem* GetItemByIndex( std::size_t index );
		CItem* GetItemByDescription( const std::string& description );

		void Add( const std::string& description, int* func );

		void Draw( );
	};

	void HandleFunctions( Menu::CMenu* menu );
}
