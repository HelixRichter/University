from PyQt6.QtWidgets import QApplication
from PyQt6.QtWidgets import QWidget


app = QApplication([]) # Передаём [], чтобы не использовать аргументы командной строки для приложения

window = QWidget()  # Создаём виджет Qt — окно.
window.show()  # Окно по умолчанию скрыто.

app.exec()  # Запускаем цикл событий.
