all: manual.pdf

manual.pdf: manual.tex
	pdflatex -interaction nonstopmode -halt-on-error manual.tex;
	pdflatex -interaction nonstopmode -halt-on-error manual.tex;

manual.tex: manual.md default.tex
	pandoc manual.md -o manual.tex --template "default.tex" --highlight-style=tango

default.tex:
	pandoc -D latex > default.tex

clean:
	rm -f manual.log manual.tex manual.out manual.blg manual.aux manual.bbl