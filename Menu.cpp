#include "Menu.h"

Menu::CMenu::CMenu( const std::string& title )
{
	this->Title = title;
}

Menu::CMenu::~CMenu( )
{
	for ( auto& item : Items )
	{
		if ( item )
		{
			delete item;
			item = nullptr;
		}
	}
}

void Menu::CMenu::HandleInput( )
{
	if ( this->nCurrent < 0 )
		this->nCurrent = nItem - 1;

	if ( this->nCurrent > nItem - 1 )
		this->nCurrent = 0;

	if ( KeyHandler::IsKeyPressed( KeyHandler::KEY_ARROW_DOWN ) )
		++this->nCurrent;
	else if ( KeyHandler::IsKeyPressed( KeyHandler::KEY_ARROW_UP ) )
		--this->nCurrent;

	if ( KeyHandler::IsKeyPressed( KeyHandler::KEY_ARROW_RIGHT ) )
	{
		CItem* item = this->GetItemByIndex( nCurrent );
		item->SetActive( true );
	}
	
	if ( KeyHandler::IsKeyPressed( KeyHandler::KEY_ARROW_LEFT ) )
	{
		CItem* item = this->GetItemByIndex( nCurrent );
		item->SetActive( false );
	}
}

bool Menu::CMenu::GetItemActive( const std::string& description )
{
	for ( const auto& item : Items )
		if ( !item->GetDescription( ).compare( description ) )
			if ( item->GetActive( ) )
				return true;
}

Menu::CItem* Menu::CMenu::GetItemByIndex( std::size_t index )
{
	for ( const auto& item : Items )
		if ( item->GetIndex( ) == index )
			return item;
}

Menu::CItem* Menu::CMenu::GetItemByDescription( const std::string& description )
{
	for ( const auto& item : Items )
		if ( !item->GetDescription( ).compare( description ) )
			return item;
}

void Menu::CMenu::Add( const std::string& description, int* func )
{
	Menu::CItem* item = new Menu::CItem( description );
	item->SetIndex( this->nItem );
	item->Function = func;
	this->Items.push_back( item );
	++this->nItem;
}

void Menu::CMenu::Draw( )
{
	this->HandleInput( );

	//DrawBox( 100, 40 + ( i * 30 ), 100, 30, white );
	//DrawOutlinedBox( 99, 39 + ( i * 30 ), 101, 31, black );
	//DrawText( 100, 40 + ( i * 30 ), yellow, this->Title );

	for ( uint16_t i = 1; i < this->Items.size( ); ++i )
	{
		Menu::CItem* item = Items[i];
		//DrawBox( 100, 40 + ( i * 30 ), 100, 30, white );
		//DrawOutlinedBox( 99, 39 + ( i * 30 ), 101, 31, black );
		//DrawText( 100, 40 + ( i * 30 ), yellow, item->GetDescription( ) );

		if ( this->nCurrent == item->GetIndex( ) )
		{
			//DrawOutlinedBox( 99, 39 + ( i * 30 ), 101, 31, Red );
		}
	}
}