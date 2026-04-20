# Скрипт для копирования необходимых Qt DLL и модулей
# Запускать из корневой директории проекта

$QtPath = "D:\Qt\6.10.2\mingw_64"
$BuildDir = ".\cmake-build-debug"
$WinDeployQt = "$QtPath\bin\windeployqt.exe"

Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host "Копирование Qt файлов для QML приложения" -ForegroundColor Cyan
Write-Host "========================================`n" -ForegroundColor Cyan

# Проверка существования windeployqt
if (Test-Path $WinDeployQt) {
    Write-Host "Использование windeployqt для автоматического копирования зависимостей..." -ForegroundColor Green
    Write-Host "Это может занять несколько секунд...`n" -ForegroundColor Gray

    & $WinDeployQt --qmldir "." --no-compiler-runtime --no-system-d3d-compiler --no-translations "$BuildDir\Moving_a_circle.exe" 2>&1 | Out-Null

    if ($LASTEXITCODE -eq 0 -or $LASTEXITCODE -eq $null) {
        Write-Host "  ✓ windeployqt успешно выполнен`n" -ForegroundColor Gray
    } else {
        Write-Host "  ⚠ windeployqt завершился с кодом: $LASTEXITCODE`n" -ForegroundColor Yellow
    }
} else {
    Write-Host "windeployqt не найден, выполняется ручное копирование..." -ForegroundColor Yellow
    Write-Host ""

    # Создание директорий
    Write-Host "Создание директорий..." -ForegroundColor Green
    New-Item -ItemType Directory -Force -Path "$BuildDir\plugins\platforms" | Out-Null
    New-Item -ItemType Directory -Force -Path "$BuildDir\qml" | Out-Null
    Write-Host "  ✓ Директории созданы`n" -ForegroundColor Gray

    # Копирование основных DLL
    Write-Host "Копирование Qt DLL файлов..." -ForegroundColor Green
$dlls = @(
    # Основные Qt модули
    "Qt6Core.dll",
    "Qt6Gui.dll",
    "Qt6Quick.dll",
    "Qt6Qml.dll",
    "Qt6QmlModels.dll",
    "Qt6Network.dll",
    "Qt6OpenGL.dll",
    "Qt6QmlWorkerScript.dll",
    "Qt6Svg.dll",
    "Qt6OpenGLWidgets.dll",

    # MinGW Runtime
    "libgcc_s_seh-1.dll",
    "libstdc++-6.dll",
    "libwinpthread-1.dll",

    # Дополнительные библиотеки
    "libdouble-conversion.dll",
    "libb2-1.dll",
    "zlib1.dll",
    "libzstd.dll",

    # ICU (Unicode support)
    "libicuin73.dll",
    "libicuuc73.dll",
    "libicudt73.dll",

    # Графические библиотеки
    "libjpeg-9.dll",
    "libpng16-16.dll",
    "libharfbuzz-0.dll",
    "libfreetype-6.dll",
    "libgraphite2.dll",
    "libbz2-1.dll",
    "libbrotlidec.dll",
    "libbrotlicommon.dll",

    # GLib и зависимости
    "libglib-2.0-0.dll",
    "libintl-8.dll",
    "libiconv-2.dll",
    "libpcre2-16-0.dll",
    "libpcre2-8-0.dll"
)

$copiedCount = 0
foreach ($dll in $dlls) {
    $sourcePath = "$QtPath\bin\$dll"
    if (Test-Path $sourcePath) {
        Copy-Item $sourcePath $BuildDir -Force -ErrorAction SilentlyContinue
        Write-Host "  ✓ $dll" -ForegroundColor Gray
        $copiedCount++
    } else {
        Write-Host "  - $dll (не найден, пропускаем)" -ForegroundColor DarkGray
    }
}
Write-Host "  Скопировано: $copiedCount DLL`n" -ForegroundColor Green

# Копирование platforms плагина
$platformPlugin = "$QtPath\plugins\platforms\qwindows.dll"
if (Test-Path $platformPlugin) {
    Copy-Item $platformPlugin "$BuildDir\plugins\platforms\" -Force
    Write-Host "  ✓ qwindows.dll (platform plugin)" -ForegroundColor Gray
}

# Копирование QML модулей
Write-Host "`nКопирование QML модулей..." -ForegroundColor Green

$qmlModules = @("QtQuick", "QtQml")
foreach ($module in $qmlModules) {
    $modulePath = "$QtPath\qml\$module"
    if (Test-Path $modulePath) {
        Copy-Item $modulePath "$BuildDir\qml\" -Recurse -Force
        Write-Host "  ✓ $module" -ForegroundColor Gray
    } else {
        Write-Host "  ✗ $module не найден" -ForegroundColor Yellow
    }
}

# Копирование qt.conf
if (Test-Path ".\qt.conf") {
    Copy-Item ".\qt.conf" $BuildDir -Force -ErrorAction SilentlyContinue
    Write-Host "`n  ✓ qt.conf скопирован" -ForegroundColor Gray
}
}

Write-Host "`n========================================" -ForegroundColor Cyan
Write-Host "✅ Готово! Попробуйте запустить приложение." -ForegroundColor Green
Write-Host "========================================`n" -ForegroundColor Cyan
Write-Host "Запуск приложения:" -ForegroundColor Yellow
Write-Host "1. Через CLion: Run → Run 'Moving_a_circle'" -ForegroundColor Gray
Write-Host "2. Напрямую: .\cmake-build-debug\Moving_a_circle.exe`n" -ForegroundColor Gray

