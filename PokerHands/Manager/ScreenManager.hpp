#pragma once

#include "Screen/BaseScreen.hpp"
#include "Screen/ScreenType.cpp"

#include <unordered_map>


class ScreenManager
{
public:
    using ScreenPointer = std::unique_ptr< BaseScreen >;

public:
    ScreenManager(const ScreenManager&) = delete;
    ScreenManager& operator=(const ScreenManager&) = delete;

public:
    static void Init();
    static void ShutDown();
    static ScreenManager& GetInstance();

private:
    ScreenManager();
    ~ScreenManager() = default;

public:
    void setScreen(ScreenType screenType);

public:
    bool isRunning() const;
    void handleEvents() const;
    void update() const;
    void render() const;

private:
    std::unordered_map<ScreenType, ScreenPointer> m_screens;
    BaseScreen* m_activeScreen{ nullptr };

};