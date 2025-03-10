#include "Window.hpp"

Window::Window(const sf::Vector2u& windowSize, const std::string& windowTitle)
{
    setup(windowSize, windowTitle);
}

Window::~Window()
{
    destroy();
}

void Window::create()
{
    constexpr auto style = sf::Style::Default;

    m_renderer.create({ m_size.x, m_size.y }, m_title, style);
    m_renderer.setFramerateLimit(60);
}

void Window::destroy()
{
    m_renderer.close();
}

void Window::handleEvents()
{
    sf::Event event{};

    while (m_renderer.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            close();
        }
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                close();
            }
        }
    }
}

void Window::beginDraw(const sf::Color& screenColor)
{
    m_renderer.clear(screenColor);
}

void Window::draw(const sf::Drawable& drawable)
{
    m_renderer.draw(drawable);
}

void Window::endDraw()
{
    m_renderer.display();
}

bool Window::isRunning() const
{
    return m_isRunning;
}

void Window::close()
{
    m_isRunning = false;
    destroy();
}

sf::Vector2u Window::getSize() const
{
    return m_size;
}

sf::RenderWindow& Window::getRenderer()
{
    return m_renderer;
}

void Window::setup(const sf::Vector2u& windowSize, const std::string& windowTitle)
{
    m_size = windowSize;
    m_title = windowTitle;
}