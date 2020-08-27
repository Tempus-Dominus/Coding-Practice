/*
	Text File Reader
	A class that works as an interface for reading information from text files.
	The class must implement the following functions,
	[DONE]1: function that opens the file
	[DONE]2: function that closes the file
	[DONE]3: function that returns a single character from the file
	[DONE]4: function that returns the next non-whitespace character from the file
	[DONE]5: function that returns a single word from the file
		- a word will be considered some amount of text that is surrounded by whitespace
	[DONE]6: function that returns the remaining line.
	[DONE]7: function that returns an integer from a file
	[DONE]8: function that returns a floating point number from a file
	[DONE]9: function that returns the current position in the file
	[DONE]10: function that sets the current position in the file absolutely
	[DONE]11: function that moves the current position in the file relatively

	[DONE]12: 3-7 without advancing the current location in the file
		- peeking
	[DONE]- In your implementation, only read one character at a time.
	[DONE]- Implement the class outside of its definition (but still in one file).
	[DONE]- Demonstrate all the classes functionality in the 'main' function.
	- You should only need to use the following libraries:
		- iostream
		- string
		- ifstream
	[DONE]- Do not use any function that "automates" reading an entire line for you,
		[DONE]your implementation of the line reading function should include comparisons of some sort.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>

class TextFileReader
{
private:

	std::ifstream _FILEDESCRIPTOR;

	bool isDigit(char Character)
	{
		return Character >= '0' && Character <= '9';
	}

	bool isAlpha(char Character)
	{
		return ( Character >= 33 && Character <= 47 ) ||
			( Character >= 58 && Character <= 126 );
	}

	bool isWhiteSpace( char Character )
	{
		return ( Character >= 9 && Character <= 13 ) ||
			( Character == 32 );
	}

	bool isLineReturn( char Character )
	{
		return ( Character == 10 );
	}

public:

	TextFileReader() {}
	
	bool open( std::string FilePath );
	bool close( std::string FilePath );
	char GetChar();
	char GetChar_Peek();
	char GetNonWhitespace();
	char GetNonWhitespace_Peek();
	std::string GetWord();
	std::string GetWord_Peek();
	std::string GetLine();
	std::string GetLine_Peek();
	long long int GetInteger();
	long long int GetInteger_Peek();
	long double GetFloat();
	int LengthOfFile();
	int CurrentPosition();
	int SetPositionAbsolute( int PositionSet );
	int SetPositionRelative( int PositionSet );
	int EOF_Reset();
	

};

int main()
{
	TextFileReader reader;

	//////FILE PATH ACCESS//////
	//If file is not located in the same directory as .cpp/.exe please use the following format:
	// "C:\\%ParentFolder%\\%ChildFolder%\\FileToAccess.txt"
	std::string FilePath = "test.txt";
	
	//////FUNCTIONALITY DEMONSTRATION//////
	reader.open( FilePath );

	std::cout << "GetChar Function: " << std::endl;
	std::cout << "Current Position: " << reader.CurrentPosition() << std::endl;
	std::cout << reader.GetChar() << '\n' << std::endl;
	
	std::cout << "GetChar_Peek Function: " << std::endl;
	std::cout << "Current Position: " << reader.CurrentPosition() << std::endl;
	std::cout << reader.GetChar_Peek() << std::endl;
	std::cout << "Current Position: " << reader.CurrentPosition() << '\n' << std::endl;
	
	std::cout << "GetNonWhitespace Function: " << std::endl;
	std::cout << "Relative Position Set To: " << reader.SetPositionRelative( 3 ) << std::endl;
	std::cout << reader.GetNonWhitespace() << std::endl;
	std::cout << "Current Position: " << reader.CurrentPosition() << '\n' << std::endl;
	
	std::cout << "GetNonWhitespace_Peek Function: " << std::endl;
	std::cout << "Relative Position Set To: " << reader.SetPositionRelative( 2 ) << std::endl;
	std::cout << reader.GetNonWhitespace_Peek() << std::endl;
	std::cout << "Current Position: " << reader.CurrentPosition() << '\n' << std::endl;
	
	std::cout << "GetWord Function: " << std::endl;
	std::cout << "Relative Position Set To: " << reader.SetPositionRelative( 2 ) << std::endl;
	std::cout << reader.GetWord() << '\n' << std::endl;
	
	std::cout << "GetWord_Peek Function: " << std::endl;
	std::cout << "Relative Position Set To: " << reader.SetPositionRelative( 2 ) << std::endl;
	std::cout << reader.GetWord_Peek() << std::endl;
	std::cout << "Current Position: " << reader.CurrentPosition() << '\n' << std::endl;
	
	std::cout << "GetLine Function: " << std::endl;
	std::cout << reader.GetLine() << '\n' << std::endl;
	
	std::cout << "GetLine_Peek Function: " << std::endl;
	std::cout << "Absolute Position Set To: " << reader.SetPositionAbsolute( 52 ) << std::endl;
	std::cout << reader.GetLine_Peek() << std::endl;
	std::cout << "Current Position: " << reader.CurrentPosition() << '\n' << std::endl;
	
	std::cout << "GetInteger Function: " << std::endl;
	std::cout << "Absolute Position Set To: " << reader.SetPositionAbsolute( 378 ) << std::endl;
	std::cout << reader.GetInteger() << '\n' << std::endl;
	
	std::cout << "GetInteger_Peek Function: " << std::endl;
	std::cout << "Absolute Position Set To: " << reader.SetPositionAbsolute( 439 ) << std::endl;
	std::cout << reader.GetInteger_Peek() << std::endl;
	std::cout << "Current Position: " << reader.CurrentPosition() << '\n' << std::endl;
	
	std::cout << "GetFloat Function: " << std::endl;
	std::cout << "Absolute Position Set To: " << reader.SetPositionAbsolute( 421 ) << std::endl;
	std::cout << std::setprecision( 12 ) << reader.GetFloat() << '\n' << std::endl;
	
	std::cout << "LengthOfFile Function: " << std::endl;
	std::cout << reader.LengthOfFile() << " Characters Long" << std::endl;

	reader.close( FilePath );

	return 0;
}

bool TextFileReader::open( std::string FilePath )
{
	_FILEDESCRIPTOR.open( FilePath, std::ios_base::in );

	if ( _FILEDESCRIPTOR.is_open() )
	{
		return _FILEDESCRIPTOR.is_open();
	}
	else
	{
		return !_FILEDESCRIPTOR.is_open();
	}
}

bool TextFileReader::close( std::string FilePath )
{
	_FILEDESCRIPTOR.close();

	if ( !_FILEDESCRIPTOR.is_open() )
	{
		return !_FILEDESCRIPTOR.is_open();
	}
	else
	{
		return _FILEDESCRIPTOR.is_open();
	}

}

char TextFileReader::GetChar()
{
	return static_cast<char>( _FILEDESCRIPTOR.get() );
}

char TextFileReader::GetChar_Peek()
{
	return static_cast<char>( _FILEDESCRIPTOR.peek() );
}

char TextFileReader::GetNonWhitespace()
{
	char charGet = static_cast<char>( _FILEDESCRIPTOR.get() );

	if ( isWhiteSpace( charGet ) == true )
	{
		return static_cast<char>( _FILEDESCRIPTOR.get() );
	}
	else if ( isWhiteSpace( charGet ) == false )
	{
		return charGet;
	}
}

char TextFileReader::GetNonWhitespace_Peek()
{
	char charGet = static_cast<char>( _FILEDESCRIPTOR.peek() );

	if ( isWhiteSpace( charGet ) == true )
	{
		_FILEDESCRIPTOR.get();
		char charPeek = static_cast<char>( _FILEDESCRIPTOR.peek() );
		_FILEDESCRIPTOR.unget();
		return charPeek;
	}
	else if ( isWhiteSpace( charGet ) == false )
	{
		return charGet;
	}
}

std::string TextFileReader::GetWord()
{
	char charGet = 0;
	std::string word = "";

	for ( int i = 0; isWhiteSpace( charGet ) == false; i++ )
	{
		_FILEDESCRIPTOR.get( charGet );
		word.push_back( charGet );
	}
	
	if ( word == " " ) return "[ERROR: Unexpected Whitespace Encountered]"; else return word;
}

std::string TextFileReader::GetWord_Peek()
{
	char charGet = 0;
	int CharGetCount = 0;
	std::string word = "";

	for ( int i = 0; isWhiteSpace( charGet ) == false; i++ )
	{
		_FILEDESCRIPTOR.get( charGet );
		word.push_back( charGet );
		CharGetCount++;
	}

	for ( int i = 0; i < CharGetCount; i++ )
	{
		_FILEDESCRIPTOR.unget();
	}

	if ( word == " " ) return "[ERROR: Unexpected Whitespace Encountered]"; else return word;
}

std::string TextFileReader::GetLine()
{
	char charGet = 0;
	std::string line = "";

	for ( int i = 0; isLineReturn( charGet ) == false; i++ )
	{
		_FILEDESCRIPTOR.get( charGet );
		line.push_back( charGet );
	}

	return line;
}

std::string TextFileReader::GetLine_Peek()
{
	char charGet = 0;
	int CharGetCount = 0;
	std::string line = "";

	for ( int i = 0; isLineReturn( charGet ) == false; i++ )
	{
		_FILEDESCRIPTOR.get( charGet );
		line.push_back( charGet );
		CharGetCount++;
	}

	for ( int i = 0; i < CharGetCount; i++ )
	{
		_FILEDESCRIPTOR.unget();
	}

	return line;
}

long long int TextFileReader::GetInteger()
{
	bool isNegative = false;
	char CurrentChar = '0';
	char StoredDigits[64];
	unsigned short int NumberOfDigits = 0;

	while ( true )
	{
		CurrentChar = static_cast<char>( _FILEDESCRIPTOR.get() );

		if ( NumberOfDigits == 0 )
		{
			if ( CurrentChar == '-' )
			{
				isNegative = true;
				//continue;
			}
			else if ( CurrentChar == '+' )
			{
				isNegative = false;
				//continue;
			}
		}

		if ( CurrentChar == '-' )
		{

		}
		else if ( isDigit( CurrentChar ) )
		{
			StoredDigits[NumberOfDigits] = CurrentChar;
			NumberOfDigits++;
		}
		else if ( !isDigit( CurrentChar ) )
		{
			break;
		}
	}

	long long int Sum = 0;
	for ( unsigned int i = 0; i < NumberOfDigits; i++ )
	{
		unsigned int digit = StoredDigits[i] - 48;

		unsigned int value = digit * std::pow( 10, NumberOfDigits - 1 - i );

		Sum += value;
	}

	if ( isNegative == true )
	{
		Sum *= -1;
	}

	return Sum;
}

long long int TextFileReader::GetInteger_Peek()
{
	bool isNegative = false;
	char CurrentChar = 0;
	int CharGetCount = 0;
	char StoredDigits[64];
	unsigned short int NumberOfDigits = 0;

	while ( true )
	{
		CurrentChar = static_cast<char>( _FILEDESCRIPTOR.get() );

		if ( NumberOfDigits == 0 )
		{
			if ( CurrentChar == '-' )
			{
				isNegative = true;
				//continue;
			}
			else if ( CurrentChar == '+' )
			{
				isNegative = false;
				//continue;
			}
		}

		if ( CurrentChar == '-' )
		{
			CharGetCount++;
		}
		else if ( isDigit( CurrentChar ) )
		{
			StoredDigits[NumberOfDigits] = CurrentChar;
			NumberOfDigits++;
			CharGetCount++;
		}
		else if ( !isDigit( CurrentChar ) )
		{
			break;
		}
	}

	long long int Sum = 0;
	for ( unsigned int i = 0; i < NumberOfDigits; i++ )
	{
		unsigned int digit = StoredDigits[i] - 48;

		unsigned int value = digit * std::pow( 10, NumberOfDigits - 1 - i );

		Sum += value;
	}

	if ( isNegative == true )
	{
		Sum *= -1;
	}

	for ( int i = 0; i < CharGetCount + 1; i++ )
	{
		_FILEDESCRIPTOR.unget();
	}

	return Sum;
}

long double TextFileReader::GetFloat()
{
	bool isNegative = false;
	char CurrentChar = '0';
	char StoredDigits[64];
	unsigned short int DecimalPosition = 0;
	unsigned short int NumberOfDigits = 0;

	while ( true )
	{
		CurrentChar = static_cast<char>( _FILEDESCRIPTOR.get() );

		if ( NumberOfDigits == 0 )
		{
			if ( CurrentChar == '-' )
			{
				isNegative = true;
				//continue;
			}
			else if ( CurrentChar == '+' )
			{
				isNegative = false;
				//continue;
			}
		}

		if ( CurrentChar == '-' )
		{

		}
		else if ( CurrentChar == '.' )
		{
			DecimalPosition = NumberOfDigits;
		}
		else if ( isDigit( CurrentChar ) )
		{
			StoredDigits[NumberOfDigits] = CurrentChar;
			NumberOfDigits++;
		}
		else if ( !isDigit( CurrentChar ) )
		{
			break;
		}
	}

	long long int Sum = 0;
	double decimal = 0;
	for ( unsigned int i = 0; i < NumberOfDigits; i++ )
	{
		unsigned int digit = StoredDigits[i] - 48;

		unsigned long long int value = digit * std::pow( 10, NumberOfDigits - 1 - i );

		Sum += value;
	}

	decimal = Sum / std::pow( 10, NumberOfDigits - DecimalPosition );

	if ( isNegative == true )
	{
		decimal *= -1;
	}

	return decimal;
}

int TextFileReader::LengthOfFile()
{
	int FileLength = 0;
	_FILEDESCRIPTOR.seekg( 0, _FILEDESCRIPTOR.end );
	FileLength = static_cast<int>( _FILEDESCRIPTOR.tellg() );
	_FILEDESCRIPTOR.seekg( 0, _FILEDESCRIPTOR.beg );
	return FileLength;
}

int TextFileReader::CurrentPosition()
{
	if ( _FILEDESCRIPTOR.eof() )
	{
		return -1; //Denotes that EOF has been reached
	}
	else
	{
		return static_cast<int>( _FILEDESCRIPTOR.tellg() );
	}
}

int TextFileReader::SetPositionAbsolute( int PositionSet )
{
	_FILEDESCRIPTOR.seekg( PositionSet, _FILEDESCRIPTOR.beg );
	return static_cast<int>( _FILEDESCRIPTOR.tellg() );
}

int TextFileReader::SetPositionRelative( int PositionSet )
{
	_FILEDESCRIPTOR.seekg( PositionSet, _FILEDESCRIPTOR.cur );
	return static_cast<int>( _FILEDESCRIPTOR.tellg() );
}

int TextFileReader::EOF_Reset()
{
	if ( _FILEDESCRIPTOR.eof() )
	{
		_FILEDESCRIPTOR.clear();
		return 0; //Denotes EOF bit has been cleared
	}
	else return -10; //Denotes inability to clear EOF bit
}
