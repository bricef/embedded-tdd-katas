
Talk.pdf: engine.js Talk.md
	npx marp --pdf --html --allow-local-files --engine ./engine.js Talk.md

.PHONY: Talk.pdf