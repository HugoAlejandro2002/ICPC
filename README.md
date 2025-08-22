# ICPC Teambook Generator

This repository automatically generates a PDF teambook from algorithm templates for ICPC competitions.

## How it works

The teambook is automatically generated using GitHub Actions whenever:
- You manually trigger the workflow

## Getting your teambook

### Manual Generation
1. **Go to the "Actions" tab**
2. **Click on "Generate ICPC Teambook"**
3. **Click "Run workflow"**
4. **Wait for completion** and download from artifacts

## Features

- **Automatic organization**: Templates are organized by folder with proper titles
- **Smart descriptions**: File descriptions are generated based on filenames
- **Professional formatting**: Clean PDF layout suitable for competitions
- **Multiple languages**: Supports C++, Python, C, and Java
- **Table of contents**: Automatically generated navigation
- **Cover page**: Includes team information fields

## Adding Templates

1. Create folders with descriptive names (e.g., `6_StringAlgorithms/`)
2. Add your template files (`.cpp`, `.py`, `.c`, `.java`)
3. Push to the repository
4. The teambook will be automatically regenerated

## Template Naming

The generator automatically creates descriptions based on filenames:
- `dijkstra.cpp` → "Dijkstra's Shortest Path (C++)"
- `segment-tree.cpp` → "Segment Tree (C++)"
- `bfs-dfs-grid.cpp` → "BFS & DFS Grid (C++)"
- `kmp-algorithm.py` → "KMP Algorithm (Python)"

## Local Development

If you want to test locally:

```bash
# Create virtual environment
python -m venv venv

# Install dependencies
pip install -r requirements.txt

# Generate teambook
python teambook_generator.py

```

## Workflow Details

The GitHub Action:
- ✅ Runs on Ubuntu latest
- ✅ Sets up Python 3.12
- ✅ Installs reportlab
- ✅ Generates PDF
- ✅ Creates release with download link
- ✅ Uploads artifact for 30 days
- ✅ Comments on pull requests

Perfect for team collaboration and competition preparation! 🏆
