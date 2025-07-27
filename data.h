#pragma pack(push, 1)
struct stAllocID
{
	int _Type;
	int _ID;
	int _None1;
	int _None2;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct stCreateStar
{
	int _Type;
	int _ID;
	int _X;
	int _Y;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct stDeleteStar
{
	int _Type;
	int _ID;
	int _None1;
	int _None2;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct stMove
{
	int _Type;
	int _ID;
	int _X;
	int _Y;
};
#pragma pack(pop)