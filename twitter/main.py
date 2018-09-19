from datetime import datetime

import sys
import tweet
from PyQt5.QtWidgets import *

class MainWindow(QWidget):
    def __init__(self, parent=None):
        super(MainWindow, self).__init__(parent)

        self.button = QPushButton('読み込み・表示')
        self.button.clicked.connect(self.output)
        self.inputText = QLineEdit()
        self.inputText.setText("")

        self.outputText = QLineEdit()
        self.outputText.setText("")
        self.outputText.setReadOnly(True)

        textLayout = QHBoxLayout()
        textLayout.addWidget(self.inputText)
        textLayout.addWidget(self.outputText)

        layout = QVBoxLayout()
        layout.addLayout(textLayout)
        layout.addWidget(self.button)
        self.setLayout(layout)
        self.setWindowTitle("tweet machine")

    def output(self):
        self.outputText.setText(self.inputText.text())
        tweet.tweet(self.inputText.text())

if __name__ == '__main__':
    app = QApplication(sys.argv)
    main_window = MainWindow()

    main_window.show()
    sys.exit(app.exec_())

tweetstr=datetime.now().strftime("%Y/%m/%d %H:%M:%S")+" "+input()
tweet.tweet(tweetstr)