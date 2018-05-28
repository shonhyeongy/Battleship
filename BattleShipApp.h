class CBattleShipApp{
public:
    CBattleShipApp();
    ~CBattleShipApp();
    
    void play();
protected:
    void Init();
    void Render();
    void Destroy();
    
protected:
    CBattleShipApp* m_pMap;
    StatPane* m_pStatPane;
    InputPane* m_pInputPane;
}
