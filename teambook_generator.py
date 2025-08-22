#!/usr/bin/env python3
"""
ICPC Teambook Generator
=======================
This script generates a PDF teambook from the Templates folder for ICPC competitions.
It organizes code templates by category with proper titles and subtitles.
"""

import os
import sys
from pathlib import Path
from reportlab.lib.pagesizes import letter, A4
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.lib.units import inch
from reportlab.platypus import SimpleDocTemplate, Paragraph, Spacer, PageBreak, Table, TableStyle
from reportlab.platypus.flowables import KeepTogether
from reportlab.lib.colors import black, blue, red, grey
from reportlab.lib.enums import TA_CENTER, TA_LEFT
from reportlab.pdfgen import canvas
from reportlab.platypus import Preformatted
from reportlab.lib import colors
import re
from datetime import datetime

class TeambookGenerator:
    def __init__(self, templates_dir, output_file="ICPC_Teambook.pdf"):
        self.templates_dir = Path(templates_dir)
        self.output_file = output_file
        self.doc = SimpleDocTemplate(
            output_file,
            pagesize=A4,
            topMargin=0.75*inch,
            bottomMargin=0.75*inch,
            leftMargin=0.5*inch,
            rightMargin=0.5*inch
        )
        self.styles = getSampleStyleSheet()
        self._setup_styles()
        self.story = []

    def _setup_styles(self):
        """Setup custom styles for the document."""
        # Title style
        self.title_style = ParagraphStyle(
            'CustomTitle',
            parent=self.styles['Title'],
            fontSize=24,
            spaceAfter=30,
            alignment=TA_CENTER,
            textColor=blue
        )
        
        # Heading styles
        self.heading1_style = ParagraphStyle(
            'CustomHeading1',
            parent=self.styles['Heading1'],
            fontSize=16,
            spaceBefore=20,
            spaceAfter=12,
            textColor=red
        )
        
        self.heading2_style = ParagraphStyle(
            'CustomHeading2',
            parent=self.styles['Heading2'],
            fontSize=14,
            spaceBefore=15,
            spaceAfter=8,
            textColor=blue
        )
        
        # Code style
        self.code_style = ParagraphStyle(
            'Code',
            parent=self.styles['Code'],
            fontSize=8,
            fontName='Courier',
            leftIndent=20,
            spaceAfter=12,
            backColor=colors.lightgrey
        )
        
        # Description style
        self.description_style = ParagraphStyle(
            'Description',
            parent=self.styles['Normal'],
            fontSize=10,
            spaceAfter=8,
            textColor=grey
        )

    def generate_category_title(self, folder_name):
        """Generate a human-readable title from folder name."""
        # Remove leading numbers and underscores
        clean_name = re.sub(r'^\d+_?', '', folder_name)
        
        # Split on underscores and camelCase
        words = re.sub(r'([a-z])([A-Z])', r'\1 \2', clean_name)
        words = words.replace('_', ' ')
        
        # Capitalize each word
        title = ' '.join(word.capitalize() for word in words.split())
        
        # Add number prefix if it existed
        number_match = re.match(r'^(\d+)', folder_name)
        if number_match:
            title = f"{number_match.group(1)}. {title}"
        
        return title

    def generate_category_description(self, folder_name, file_count):
        """Generate a description for a category based on folder name and contents."""
        clean_name = re.sub(r'^\d+_?', '', folder_name)
        
        # Convert snake_case and camelCase to readable format
        readable_name = re.sub(r'([a-z])([A-Z])', r'\1 \2', clean_name)
        readable_name = readable_name.replace('_', ' ').lower()
        
        return f"{readable_name.capitalize()} algorithms and implementations ({file_count} templates)"

    def generate_file_description(self, filename):
        """Generate description for a file based on its name."""
        name_without_ext = filename.split('.')[0].lower()
        extension = filename.split('.')[-1].lower()
        
        # Language indicator
        lang_map = {
            'cpp': 'C++',
            'py': 'Python',
            'c': 'C',
            'java': 'Java',
            'js': 'JavaScript'
        }
        lang = lang_map.get(extension, extension.upper())
        
        # Convert snake_case and dash-separated names to readable format
        def snake_to_sentence(text):
            """Convert snake_case or dash-separated text to sentence case."""
            # Replace underscores and dashes with spaces
            text = text.replace('_', ' ').replace('-', ' ')
            # Split into words and capitalize each
            words = text.split()
            # Handle common abbreviations
            abbreviations = {'bfs': 'BFS', 'dfs': 'DFS', 'lcs': 'LCS', 'lis': 'LIS', 
                           'gcd': 'GCD', 'lcm': 'LCM', 'fft': 'FFT', 'ntt': 'NTT',
                           'bit': 'BIT', 'mst': 'MST', 'dp': 'DP', 'io': 'I/O'}
            
            formatted_words = []
            for word in words:
                if word.lower() in abbreviations:
                    formatted_words.append(abbreviations[word.lower()])
                else:
                    formatted_words.append(word.capitalize())
            
            return ' '.join(formatted_words)
        
        # Convert filename to readable description
        readable_name = snake_to_sentence(name_without_ext)
        return f"{readable_name} ({lang})"

    def get_all_categories(self):
        """Get all category directories from the templates folder."""
        categories = []
        for item in self.templates_dir.iterdir():
            if item.is_dir():
                categories.append(item.name)
        return sorted(categories)

    def add_cover_page(self):
        """Add a cover page to the teambook."""
        # Main title
        title = Paragraph("ICPC TEAMBOOK", self.title_style)
        self.story.append(title)
        self.story.append(Spacer(1, 0.5*inch))
        
        # Subtitle
        subtitle_style = ParagraphStyle(
            'Subtitle',
            parent=self.styles['Normal'],
            fontSize=16,
            alignment=TA_CENTER,
            textColor=black
        )
        subtitle = Paragraph("Competitive Programming Templates & Algorithms", subtitle_style)
        self.story.append(subtitle)
        self.story.append(Spacer(1, 1*inch))
        
        # Team info table
        team_data = [
            ['Team Members:', ''],
            ['Member 1:', '_' * 30],
            ['Member 2:', '_' * 30],
            ['Member 3:', '_' * 30],
            ['', ''],
            ['University:', '_' * 30],
            ['Coach:', '_' * 30],
            ['Date:', datetime.now().strftime('%B %d, %Y')]
        ]
        
        team_table = Table(team_data, colWidths=[2*inch, 3*inch])
        team_table.setStyle(TableStyle([
            ('FONTSIZE', (0, 0), (-1, -1), 12),
            ('ALIGN', (0, 0), (0, -1), 'RIGHT'),
            ('VALIGN', (0, 0), (-1, -1), 'MIDDLE'),
            ('BOTTOMPADDING', (0, 0), (-1, -1), 8),
        ]))
        
        self.story.append(team_table)
        self.story.append(PageBreak())

    def read_file_content(self, file_path):
        """Read and return the content of a file."""
        try:
            with open(file_path, 'r', encoding='utf-8') as f:
                return f.read()
        except UnicodeDecodeError:
            try:
                with open(file_path, 'r', encoding='latin-1') as f:
                    return f.read()
            except Exception as e:
                return f"Error reading file: {str(e)}"
        except Exception as e:
            return f"Error reading file: {str(e)}"

    def get_file_description(self, filename):
        """Get description for a file based on its name."""
        return self.generate_file_description(filename)

    def add_code_section(self, file_path, filename):
        """Add a code section to the story."""
        # File header
        description = self.get_file_description(filename)
        header = Paragraph(f"<b>{filename}</b> - {description}", self.heading2_style)
        
        # Read file content
        content = self.read_file_content(file_path)
        
        # Create preformatted text for code
        # Split content into lines and rejoin to ensure proper formatting
        lines = content.split('\n')
        
        # Limit line length to prevent overflow
        formatted_lines = []
        for line in lines:
            if len(line) > 100:  # If line is too long, wrap it
                while len(line) > 100:
                    formatted_lines.append(line[:100])
                    line = '    ' + line[100:]  # Indent continuation
                if line.strip():
                    formatted_lines.append(line)
            else:
                formatted_lines.append(line)
        
        formatted_content = '\n'.join(formatted_lines)
        
        code_block = Preformatted(
            formatted_content,
            style=self.code_style
        )
        
        # Keep header and code together
        section = KeepTogether([
            header,
            Spacer(1, 6),
            code_block,
            Spacer(1, 12)
        ])
        
        self.story.append(section)

    def process_category(self, category_dir, category_name):
        """Process all files in a category directory."""
        # Get all code files in the directory
        code_files = []
        for file_path in category_dir.iterdir():
            if file_path.is_file() and file_path.suffix in ['.cpp', '.py', '.c', '.java']:
                code_files.append(file_path)
        
        if not code_files:  # Skip empty directories
            return
        
        # Generate category title and description
        title = self.generate_category_title(category_name)
        description = self.generate_category_description(category_name, len(code_files))
        
        # Add category title
        title_para = Paragraph(title, self.heading1_style)
        self.story.append(title_para)
        
        # Add category description
        desc_para = Paragraph(description, self.description_style)
        self.story.append(desc_para)
        self.story.append(Spacer(1, 12))
        
        # Sort files for consistent ordering
        code_files.sort(key=lambda x: x.name)
        
        # Process each file
        for file_path in code_files:
            self.add_code_section(file_path, file_path.name)

    def add_table_of_contents(self):
        """Add a table of contents."""
        toc_title = Paragraph("Table of Contents", self.heading1_style)
        self.story.append(toc_title)
        self.story.append(Spacer(1, 12))
        
        toc_data = []
        categories = self.get_all_categories()
        
        for category_name in categories:
            category_dir = self.templates_dir / category_name
            if category_dir.exists() and category_dir.is_dir():
                # Get all code files in the directory
                code_files = []
                for file_path in category_dir.iterdir():
                    if file_path.is_file() and file_path.suffix in ['.cpp', '.py', '.c', '.java']:
                        code_files.append(file_path)
                
                if code_files:  # Only add categories with code files
                    category_title = self.generate_category_title(category_name)
                    toc_data.append([category_title, ""])
                    
                    # List files in category
                    for file_path in sorted(code_files, key=lambda x: x.name):
                        description = self.get_file_description(file_path.name)
                        toc_data.append([f"  • {file_path.name}", description])
        
        if toc_data:
            toc_table = Table(toc_data, colWidths=[3*inch, 4*inch])
            toc_table.setStyle(TableStyle([
                ('FONTSIZE', (0, 0), (-1, -1), 10),
                ('VALIGN', (0, 0), (-1, -1), 'TOP'),
                ('BOTTOMPADDING', (0, 0), (-1, -1), 4),
                ('FONTNAME', (0, 0), (0, -1), 'Helvetica-Bold'),
            ]))
            self.story.append(toc_table)
        
        self.story.append(PageBreak())

    def generate_teambook(self):
        """Generate the complete teambook PDF."""
        print("Generating ICPC Teambook...")
        
        # Add cover page
        self.add_cover_page()
        
        # Add table of contents
        self.add_table_of_contents()
        
        # Process each category
        categories = self.get_all_categories()
        for category_name in categories:
            category_dir = self.templates_dir / category_name
            if category_dir.exists() and category_dir.is_dir():
                # Check if directory has any code files
                has_code_files = any(
                    f.is_file() and f.suffix in ['.cpp', '.py', '.c', '.java']
                    for f in category_dir.iterdir()
                )
                
                if has_code_files:
                    category_title = self.generate_category_title(category_name)
                    print(f"Processing {category_title}...")
                    self.process_category(category_dir, category_name)
                    self.story.append(PageBreak())
        
        # Build the PDF
        print(f"Building PDF: {self.output_file}")
        self.doc.build(self.story)
        print(f"Teambook generated successfully: {self.output_file}")

def main():
    """Main function to run the teambook generator."""
    # Check if reportlab is installed
    try:
        import reportlab
    except ImportError:
        print("Error: reportlab is required to generate PDFs.")
        print("Install it using: pip install reportlab")
        sys.exit(1)
    
    # Simple argument handling for GitHub Actions
    templates_dir = "Templates"
    output_file = "ICPC_Teambook.pdf"
    
    # Allow command line override
    if len(sys.argv) > 1:
        templates_dir = sys.argv[1]
    if len(sys.argv) > 3 and sys.argv[2] == "-o":
        output_file = sys.argv[3]
    
    # Get the script directory and templates directory
    script_dir = Path(__file__).parent
    templates_path = script_dir / templates_dir
    
    if not templates_path.exists():
        print(f"Error: Templates directory not found at {templates_path}")
        available_dirs = [item.name for item in script_dir.iterdir() 
                         if item.is_dir() and not item.name.startswith('.')]
        if available_dirs:
            print(f"Available directories: {', '.join(available_dirs)}")
        sys.exit(1)
    
    # Check if directory has any template files
    has_templates = any(
        f.suffix in ['.cpp', '.py', '.c', '.java']
        for category_dir in templates_path.iterdir()
        if category_dir.is_dir()
        for f in category_dir.iterdir()
        if f.is_file()
    )
    
    if not has_templates:
        print(f"Warning: No template files found in {templates_path}")
        print("Looking for .cpp, .py, .c, or .java files in subdirectories")
    
    # Generate teambook
    generator = TeambookGenerator(templates_path, output_file)
    generator.generate_teambook()

if __name__ == "__main__":
    main()