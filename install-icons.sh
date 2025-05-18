#!/bin/bash

ICON_SRC="icons/pomodoro.png"
ICON_NAME="pomodoro.png"
ICON_SIZES=(16 22 24 32 36 44 48 64 72 96 128 150 192 256 310 512 720 1024)

if ! command -v convert &> /dev/null; then
    echo "❌ Требуется ImageMagick (команда 'convert'). Установи: sudo apt install imagemagick"
    exit 1
fi

for size in "${ICON_SIZES[@]}"; do
    TARGET_DIR="/usr/share/icons/hicolor/${size}x${size}/apps"
    sudo mkdir -p "$TARGET_DIR"
    sudo convert "$ICON_SRC" -resize ${size}x${size} "$TARGET_DIR/$ICON_NAME"
done

# scalable — если у тебя есть SVG
# sudo mkdir -p /usr/share/icons/hicolor/scalable/apps
# sudo cp icons/pomodoro.svg /usr/share/icons/hicolor/scalable/apps/pomodoro.svg

# Обновление кэша иконок
sudo gtk-update-icon-cache -f /usr/share/icons/hicolor

echo "✔ Иконки масштабированы, установлены и кэш обновлён."
