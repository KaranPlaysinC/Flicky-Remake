class FieldManagerC
{
public:
	static FieldManagerC	*CreateInstance();
	static FieldManagerC	*GetInstance() {return sInstance;};
	~FieldManagerC(){};

	FieldC* getFieldPtr1();
	FieldC* getFieldPtr2();
	FieldC* getFieldPtr3();
	FieldC* getFieldPtr4();
	FieldC* getFieldPtr5();
	FieldC* getFieldPtr6();
	FieldC* getFieldPtr7();
	FieldC* getFieldPtr8();
	FieldC* getFieldPtr9();
	FieldC* getFieldPtr10();
	FieldC* getFieldPtr11();
	FieldC* getFieldPtr12();
	void init();
	void renderField();
	void shutdown();
private:
	static FieldManagerC *sInstance;
	FieldManagerC(){};
	
	FieldC* mFieldPtr1 = nullptr;
	FieldC* mFieldPtr2 = nullptr;
	FieldC* mFieldPtr3 = nullptr;
	FieldC* mFieldPtr4 = nullptr;
	FieldC* mFieldPtr5 = nullptr;
	FieldC* mFieldPtr6 = nullptr;
	FieldC* mFieldPtr7 = nullptr;
	FieldC* mFieldPtr8 = nullptr;
	FieldC* mFieldPtr9 = nullptr;
	FieldC* mFieldPtr10 = nullptr;
	FieldC* mFieldPtr11 = nullptr;
};